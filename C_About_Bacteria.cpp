#include <bits/stdc++.h>
#define lol long long
using namespace std;
// bool limit(lol a, lol n)
// {
//     lol c = 0;
//     lol v = LONG_LONG_MAX;
//     lol q = 1;
//     while (v >= a)
//     {
//         c++;
//         v /= a;
//     }
//     return c >= n;
// }

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol k, b, n, t;
    cin >> k >> b >> n >> t;
    if (k == 1)
    {
        cout << max((long long)ceill((b * 1ll * n - t + 1) / (long double)b), 0ll);
    }
    else
    {
        // if (!limit(k, n))
        // {
        //     cout << n;
        // }
        // else
        {
            lol st = 0, e = 31;
            while (st != e - 1)
            {
                lol m = (st + e) / 2;
                if (powl(k, m) <= t)
                {
                    st = m;
                }
                else
                    e = m;
            }

            lol i;
            // k, b, n, t; e=1

            for (i = st; i >= 0; i--)
            {
                lol n2 = n - i;
                if (n2 < 0)
                    continue;
                lol v = 0;
                for (lol j = 0; j < n - n2; j++)
                {
                    v += powl(k, j) * 1ll * b;
                }

                lol q = t - powl(k, i);

                if (v <= q)
                {
                    break;
                }
            }
            cout << n - i;
        }
    }

    return 0;
}