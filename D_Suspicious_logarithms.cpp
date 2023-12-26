#include <bits/stdc++.h>
using namespace std;
#define lol unsigned long long
lol logbase(lol a, lol b)
{
    lol v = 1;
    for (lol i = 0;; i++)
    {
        if (v > a)
            return i - 1;
        v = v * 1ll * b;
    }
    return -1;
}
lol pw(lol a, lol b)
{
    lol r = 1;
    while (b > 0)
    {
        if (b % 2)
            r = r * 1ll * a;
        a = a * 1ll * a;
        b /= 2ll;
    }
    return r;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol q;
    cin >> q;
    while (q--)
    {
        lol l, r;
        cin >> l >> r;
        lol s = l;
        lol ans = 0;
        lol mod = 1e9 + 7;
        while (s <= r)
        {

            lol b = logbase(s, 2ll);
            lol val = logbase(s, b);

            lol r1 = (1ll << (b + 1)) - 1;
            lol r2 = pw(b, val + 1) - 1;

            r1 = min(r1, min(r, r2));
            ans += (val * 1ll * (r1 - s + 1)) % mod;
            ans %= mod;
            s = r1 + 1;
        }
        cout << ans << '\n';
    }

    return 0;
}
