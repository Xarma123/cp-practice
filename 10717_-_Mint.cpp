#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol lcm(lol a, lol b, lol c, lol d)
{
    a = a * 1ll * b / __gcd(a, b);
    a = a * 1ll * c / __gcd(a, c);
    a = a * 1ll * d / __gcd(a, d);
    return a;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, t;
    while (cin >> n >> t)
    {
        if (n == 0 && t == 0)
            break;
        lol c[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> c[i];
        }
        lol ta[t];
        lol mx = LONG_LONG_MIN;
        for (lol i = 0; i < t; i++)
        {
            cin >> ta[i];
            mx = max(mx, ta[i]);
        }

        lol l[t], u[t];
        memset(l, -1, sizeof(l));
        memset(u, -1, sizeof(u));

        for (lol i1 = 0; i1 < n; i1++)
        {
            for (lol i2 = i1 + 1; i2 < n; i2++)
            {
                for (lol i3 = i2 + 1; i3 < n; i3++)
                {
                    for (lol i4 = i3 + 1; i4 < n; i4++)
                    {
                        lol lc = lcm(c[i1], c[i2], c[i3], c[i4]);
                        for (lol j = 0; j < t; j++)
                        {
                            l[j] = max(l[j], (ta[j] / lc) * 1ll * lc);
                            if (u[j] == -1)
                                u[j] = (((ta[j] + lc - 1) / lc) * 1ll * lc);
                            else if (u[j] > (((ta[j] + lc - 1) / lc) * 1ll * lc))
                                u[j] = (((ta[j] + lc - 1) / lc) * 1ll * lc);
                        }
                    }
                }
            }
        }
        for (lol i = 0; i < t; i++)
        {
            cout << l[i] << " " << u[i] << endl;
        }
    }

    return 0;
}