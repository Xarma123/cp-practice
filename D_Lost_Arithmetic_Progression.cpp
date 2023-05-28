#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol lcm(lol a, lol b)
{
    return (a * 1ll * b) / (long long)__gcd(a, b);
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol b, q, y;
        cin >> b >> q >> y;
        lol c, r, z;
        cin >> c >> r >> z;
        if (r % q != 0)
        {
            cout << 0 << '\n';
        }
        else
        {
            if (c < b)
            {
                cout << 0 << '\n';
                continue;
            }
            if (((c - b) % q != 0))
            {
                cout << 0 << '\n';
                continue;
            }
            else if (((c - b) / q + 1 > y))
            {
                cout << 0 << '\n';
                continue;
            }
            else if (((c - b) / q + 1 < 0))
            {
                cout << 0 << '\n';
                continue;
            }
            lol last = c + r * 1ll * (z - 1);
            if ((last - b) / q + 1 > y)
            {
                cout << 0 << '\n';
                continue;
            }
            else if ((last - b) / q + 1 < 0)
            {
                cout << 0 << '\n';
                continue;
            }
            if (c - r < b)
            {
                cout << -1 << '\n';
                continue;
            }
            if (last + r > b + q * 1ll * (y - 1))
            {
                cout << -1 << '\n';
                continue;
            }

            lol ans = 0;
            lol mod = 1e9 + 7;
            for (lol i = 1; i * 1ll * i <= r; i++)
            {
                if (r % i == 0)
                {
                    if (lcm(i, q) == r)
                    {
                        lol d = i;
                        lol rt = r / d;
                        lol lf = r / d;

                        ans += (rt * 1ll * lf) % mod;
                        ans %= mod;
                    }
                    if (r / i != i)
                    {
                        if (lcm(r / i, q) == r)
                        {
                            lol d = r / i;
                            lol rt = r / d;
                            lol lf = r / d;
                            ans += (rt * 1ll * lf) % mod;
                            ans %= mod;
                        }
                    }
                }
            }
            cout << ans << '\n';
        }
    }

    return 0;
}