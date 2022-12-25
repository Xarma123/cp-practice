#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m, q;
    cin >> n >> m >> q;
    string c[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    lol cum[n + 1][m + 1];
    for (lol i = 0; i <= n; i++)
    {
        for (lol j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                cum[i][j] = 0;
            else
            {
                cum[i][j] = cum[i][j - 1] + cum[i - 1][j] - cum[i - 1][j - 1] + (c[i - 1][j - 1] == '1');
            }
        }
    }
    lol ans = 0;
    while (q--)
    {
        lol a, b, c, d;
        cin >> a >> b >> c >> d;
        // a x c    b y d

        for (lol i = a - 1; i <= c; i++)
        {
            map<lol, lol> mp;
            for (lol j = b; j <= d; j++)
            {
                cum[i][j] - cum[i][b - 1]
            }
        }
    }

    return 0;
}