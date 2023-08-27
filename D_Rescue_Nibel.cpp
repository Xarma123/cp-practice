#include <bits/stdc++.h>
using namespace std;
#define lol long long
lol bpow(lol a, lol b, lol m)
{
    lol r = 1;
    while (b > 0)
    {
        if ((b & 1))
            r = (r * 1ll * a) % m;
        a = (a * 1ll * a) % m;
        b /= 2;
    }
    return r;
}
lol mod(lol a, lol m)
{
    return bpow(a, m - 2, m);
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, k;
    cin >> n >> k;
    vector<lol> l, r;
    for (lol i = 0; i < n; i++)
    {
        lol a, b;
        cin >> a >> b;
        l.push_back(a);
        r.push_back(b);
    }
    lol m = 998244353;
    lol fact[n + 1];
    fact[0] = 1;
    for (lol i = 1; i <= n; i++)
    {
        fact[i] = (fact[i - 1] * 1ll * i) % m;
    }
    lol inv[n + 1];
    inv[0] = 1;
    for (lol i = 1; i <= n; i++)
    {
        inv[i] = (inv[i - 1] * 1ll * mod(i, m)) % m;
       
    }
    lol ans = 0;
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    lol i = 0, j = 0;
    lol c = 0;
    while (i < l.size() && j < r.size())
    {
        if (l[i] <= r[j])
        {
            c++;
            if (c - 1 >= k - 1)
            {
                ans += (((fact[c - 1] * 1ll * inv[k - 1]) % m) * 1ll * inv[c - k ]) % m;
                ans %= m;
            }
            i++;
        }
        else
        {
            c--;
            j++;
        }
    }
    cout << ans;
}