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
        lol a, b;
        cin >> a >> b;
        lol g = __gcd(a, b);
        lol r = b / g;
        vector<lol> d;
        for (lol i = 2; i * 1ll * i <= r; i++)
        {
            if (r % i == 0)
            {
                d.push_back(i);
            }
            while (r % i == 0)
            {
                r /= i;
            }
        }
        if (r > 1)
            d.push_back(r);
        lol n = d.size();
        lol s = a, e = a + b - 1;
        lol ans = (e / g) - ((s - 1) / g);
        for (lol i = 0; i < (1ll << n); i++)
        {
            lol c = g;
            lol f = -1;
            for (lol j = 0; j < n; j++)
            {
                if ((i & (1ll << j)))
                {
                    f *= -1;
                    c = c * 1ll * d[j];
                }
            }
            if (c != g)
            {
                if (f > 0)
                    ans -= (e / c) - ((s - 1) / c);
                else
                    ans += (e / c) - ((s - 1) / c);
            }
        }
        cout << ans << '\n';
    }
}