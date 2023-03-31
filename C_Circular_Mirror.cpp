#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol mod = 998244353;
lol pw(lol a, lol b)
{
    lol r = 1;
    while (b > 0)
    {
        if (b % 2)
            r = (r * 1ll * a) % mod;
        a = (a * 1ll * a) % mod;
        b /= 2;
    }
    return r;
}
lol fact[300005];
lol invfact[300005];
lol ncr(lol n, lol r)
{
    lol ans = fact[n];
    ans = (ans * 1ll * invfact[r]) % mod;
    ans = (ans * 1ll * invfact[n - r]) % mod;
    return ans;
}
lol npr(lol n, lol r)
{
    lol ans = fact[n];
    ans = (ans * 1ll * invfact[n - r]) % mod;
    return ans;
}

lol modInverse(lol A, lol M)
{
    lol m0 = M;
    lol y = 0, x = 1;
    if (M == 1)
        return 0;
    while (A > 1)
    {
        int q = A / M;
        int t = M;

        M = A % M, A = t;
        t = y;

        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += m0;
    return x;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (lol i = 0; i < 300005; i++)
    {
        if (i == 0)
            fact[i] = 1;
        else
            fact[i] = (i * 1ll * fact[i - 1]) % mod;
    }
    invfact[0] = 1;
    for (lol i = 1; i < 300005; i++)
    {
        invfact[i] = (invfact[i - 1] * 1ll * modInverse(i, mod)) % mod;
    }

    lol n, m;
    cin >> n >> m;
    lol d[n];
    lol s = 0;
    for (lol i = 0; i < n; i++)
    {
        cin >> d[i];
        s += d[i];
    }

    if (s % 2)
    {
        lol ans = 1;
        for (lol i = 0; i < n; i++)
        {
            ans = (ans * 1ll * m) % mod;
        }
        cout << ans;
    }
    else
    {
        s /= 2;
        lol de = 0;
        set<lol> x;
        lol st = 0;
        for (lol i = 0; i < n; i++)
        {
            x.insert(st);
            st += d[i];
        }
        st = 0;
        for (lol i = 0; i < n; i++)
        {
            if (x.count(st + s))
            {
                de++;
            }
            st += d[i];
        }
        lol ans = 0;

        for (lol x = 0; x <= de; x++)
        {
            // (de c x)*1ll*(m p x)*( ((m-x)*(m-x-1))^(de-x) )*((m-x)^(n-de*2ll))
            if (m >= x)
            {
                lol v = ncr(de, x);
                v = (v * 1ll * npr(m, x)) % mod;
                if (m - x == 1 && de - x > 0)
                {
                    continue;
                }
                v = (v * 1ll * pw(m - x, n - de - x)) % mod;
                v = (v * 1ll * pw(m - x - 1, de - x)) % mod;
                ans = (ans + v) % mod;
            }
            cout << endl;
        }
        cout << ans;
    }

    return 0;
}