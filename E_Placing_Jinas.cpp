#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol mod = 1e9 + 7;
map<lol, lol> f;
lol inv(lol A)
{
    lol M = mod;
    lol m0 = M;
    lol y = 0, x = 1;

    if (M == 1)
        return 0;

    while (A > 1)
    {
        // q is quotient
        lol q = A / M;
        lol t = M;

        // m is remainder now, process same as
        // Euclid's algo
        M = A % M, A = t;
        t = y;

        // Update y and x
        y = x - q * y;
        x = t;
    }

    // Make x positive
    if (x < 0)
        x += m0;

    return x;
}
lol fact(lol a)
{
    if (a == 0)
        return 1ll;
    if (f.count(a))
        return f[a];
    return f[a] = ((a * 1ll * fact(a - 1)) % mod);
}
lol invfact(lol a)
{
    if (a == 0)
        return 1ll;
    if (f.count(a))
        return inv(f[a]);
    f[a] = ((a * 1ll * fact(a - 1)) % mod);
    return inv(f[a]);
}
lol ncr(lol n, lol r)
{
    lol v = fact(n);
    v = (v * 1ll * invfact(n - r)) % mod;
    v = (v * 1ll * invfact(r)) % mod;
    return v;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol a[n + 1];
    for (lol i = 0; i <= n; i++)
    {
        cin >> a[i];
    }
    lol ans = 0;
    for (lol j = 0; j < a[0]; j++)
    {
        lol s = 0;
        lol e = n + 1;
        while (s != e - 1)
        {
            lol m = (s + e) / 2;
            if (m == n + 1)
            {
                e = m;
            }
            else if (a[m] > j)
                s = m;
            else
                e = m;
        }
        ans += ncr(j + s + 1, j + 1);
        ans %= mod;
    }
    cout << ans;

    return 0;
}