#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol px, py;
        cin >> px >> py;
        lol ax, ay;
        cin >> ax >> ay;
        lol bx, by;
        cin >> bx >> by;
        long double s = 0, e = 1e18;
        while (abs(s - e) > 1e-11)
        {
            long double m = (s + e) / (long double)2;

            long double d1 = ax * 1ll * ax + ay * 1ll * ay;
            if (d1 <= m * (long double)m)
            {
                d1 = (ax - px) * 1ll * (ax - px) + (ay - py) * 1ll * (ay - py);
                if (d1 <= m * (long double)m)
                {
                    e = m;
                    continue;
                }
            }
            long double d2 = bx * 1ll * bx + by * 1ll * by;
            if (d2 <= m * (long double)m)
            {
                d2 = (bx - px) * 1ll * (bx - px) + (by - py) * 1ll * (by - py);
                if (d2 <= m * (long double)m)
                {
                    e = m;
                    continue;
                }
            }
            d1 = ax * 1ll * ax + ay * 1ll * ay;
            d2 = bx * 1ll * bx + by * 1ll * by;
            if (d1 <= m * (long double)m)
            {
                d2 = (bx - px) * 1ll * (bx - px) + (by - py) * 1ll * (by - py);
                if (d2 <= m * (long double)m)
                {
                    long double r = sqrtl((ax - bx) * 1ll * (ax - bx) + (ay - by) * 1ll * (ay - by));
                    if (r <= m + m)
                    {
                        e = m;
                        continue;
                    }
                }
            }
            if (d2 <= m * (long double)m)
            {
                d1 = (ax - px) * 1ll * (ax - px) + (ay - py) * 1ll * (ay - py);
                if (d1 <= m * (long double)m)
                {
                    long double r = sqrtl((ax - bx) * 1ll * (ax - bx) + (ay - by) * 1ll * (ay - by));
                    if (r <= m + m)
                    {
                        e = m;
                        continue;
                    }
                }
            }
            s = m;
        }
        cout << fixed << setprecision(10) << e << '\n';
    }
}