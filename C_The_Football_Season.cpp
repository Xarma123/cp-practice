#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, p, w, d;
    cin >> n >> p >> w >> d;
    if ((long long)ceill(p / (long double)w) > n)
        cout << -1;
    else
    {
        if (p % d == 0)
        {
            if (p / d <= n)
            {
                cout << 0 << " " << (p / d) << " " << n - (p/d) << '\n';
                return 0;
            }
        }
        lol r = p % d;
        lol z = -1, zr = -1;
        for (lol i = 1; i <= 1e5; i++)
        {
            if ((w * 1ll * i) % d == 0)
            {
                if (z == -1)
                    z = i;
            }
            if ((w * 1ll * i) % d == r)
            {
                if (zr == -1)
                    zr = i;
            }
        }
        if (zr == -1)
            cout << -1;
        else
        {
            lol v = w * 1ll * zr;
            if (p < v)
            {
                cout << -1;
                return 0;
            }
            lol v2 = w * 1ll * z;
            lol k1 = (p - v) / v2;
            if (((p - v - k1 * 1ll * v2) / d) + zr + z * 1ll * k1 <= n)
            {
                cout << zr + z * 1ll * k1 << " " << ((p - v - k1 * 1ll * v2) / d) << " " << n - (zr + z * 1ll * k1) - (((p - v - k1 * 1ll * v2) / d)) << '\n';
            }
            else
                cout << -1;
        }
    }
}