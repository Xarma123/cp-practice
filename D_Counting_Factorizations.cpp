#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol modInverse(lol A, lol M)
{
    lol m0 = M;
    lol y = 0, x = 1;

    if (M == 1)
        return 0;

    while (A > 1)
    {
        lol q = A / M;
        lol t = M;
        M = A % M, A = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += m0;

    return x;
}
lol fact[1000005];
lol invfact[1000005];
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    lol m = 998244353;
    bool p[1000005];
    memset(p, true, sizeof(p));
    p[1] = false;
    for (lol i = 2; i < 1000005; i++)
    {
        if (p[i])
        {
            for (lol j = i * 1ll * i; j < 1000005; j += i)
                p[j] = false;
        }
    }
    fact[0] = 1;
    for (lol i = 1; i < 1000005; i++)
    {
        fact[i] = (fact[i - 1] * 1ll * i) % m;
    }
    invfact[0] = modInverse(1, m);
    for (lol i = 1; i < 1000005; i++)
    {
        invfact[i] = (invfact[i - 1] * 1ll * modInverse(i, m)) % m;
    }
    lol n;
    cin >> n;
    n *= 2ll;
    lol a[n];
    map<lol, lol> composite, primes;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        if (p[a[i]])
            primes[a[i]]++;
        else
        {
            composite[a[i]]++;
        }
    }
    if (primes.size() < n / 2)
        cout << 0;
    else if (primes.size() >= n / 2)
    {
        lol q = primes.size();
        lol ans = 1;
        ans = (ans * 1ll * fact[q]) % m;
        ans = (ans * 1ll * invfact[q - (n / 2)]) % m;
        cout << ans;
    }

    return 0;
}