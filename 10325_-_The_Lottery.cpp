#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol lcm(lol a, lol b)
{
    return a * 1ll * b / __gcd(a, b);
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    while (cin >> n >> m)
    {
        vector<lol> x(m, 0);
        for (lol i = 0; i < m; i++)
        {
            cin >> x[i];
        }
        lol ans = 0;
        for (lol i = 0; i < (1 << m); i++)
        {
            lol v = 1;
            lol s = -1;
            for (lol j = 0; j < m; j++)
            {
                if ((i & (1 << j)))
                {
                    v = lcm(v, x[j]);
                    s *= -1;
                }
            }

            if (v != 1)
            {
                ans += (n / v) * 1ll * s;
            }
        }
        cout << n - ans << endl;
    }

    return 0;
}