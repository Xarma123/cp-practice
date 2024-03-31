#include <bits/stdc++.h>
using namespace std;
#define lol long long
lol mod = 998244353;
lol fact[5000005];
lol inv[5000005];
lol bpow(lol a, lol b)
{
    lol r = 1;
    while (b > 0)
    {
        if (b % 2)
            r = (r * 1ll * a) % mod;
        b /= 2ll;
        a = (a * 1ll * a) % mod;
    }
    return r;
}
lol in(lol a)
{
    return bpow(a, mod - 2);
}
lol ncr(lol n, lol r)
{

    lol ans = fact[n];
    ans = ((ans * inv[r]) % mod);
    ans = ((ans * inv[n - r]) % mod);
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fact[0] = 1;
    for (lol i = 1; i < 4000005; i++)
    {
        fact[i] = (fact[i - 1] * 1ll * i) % mod;
    }
    inv[0] = 1;
    inv[1] = 1;
    for (lol i = 2; i < 4000005; i++)
    {
        inv[i] = (inv[i - 1] * 1ll * in(i)) % mod;
    }
    lol t;
    cin >> t;
    while (t--)
    {
        lol c1, c2, c3, c4;
        cin >> c1 >> c2 >> c3 >> c4;
        if (c1 == c2 && c1 == 0)
        {
            if (c3 != 0 && c4 != 0)
                cout << 0 << '\n';
            else
            {
                cout << 1 << '\n';
            }
        }
        else if (c1 == c2)
        {
            cout << (((ncr(c3 + c1 - 1, c1 - 1) * 1ll * ncr(c4 + c1, c1)) % mod) +
                     ((ncr(c3 + c1, c1) * 1ll * ncr(c4 + c1 - 1, c1 - 1)) % mod)) %
                        mod
                 << '\n';
        }
        else if (c2 == c1 + 1)
        {
            cout << ((ncr(c3 + c2 - 1, c2 - 1) * 1ll * ncr(c4 + c2 - 1, c2 - 1)) % mod) << '\n';
        }
        else if (c1 == c2 + 1)
        {
            cout << ((ncr(c3 + c1 - 1, c1 - 1) * 1ll * ncr(c4 + c1 - 1, c1 - 1)) % mod) << '\n';
        }
        else
            cout << 0 << '\n';
    }

    return 0;
}
