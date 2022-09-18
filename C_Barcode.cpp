#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m, x, y;
    cin >> n >> m >> x >> y;
    string a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lol cost[m][2];
    for (lol j = 0; j < m; j++)
    {
        lol c = 0;
        for (lol i = 0; i < n; i++)
        {
            if (a[i][j] == '.')
                c++;
        }
        cost[j][0] = n - c;
        cost[j][1] = c;
    }

    lol dp[m + 1][2];
    dp[0][0] = 0;
    dp[0][1] = 0;
    for (lol i = 1; i <= m; i++)
    {
        dp[i][0] = LONG_LONG_MAX;
        dp[i][1] = LONG_LONG_MAX;
        lol w = 0, b = 0;
        for (lol j = i; j > 0 && j > i - x; j--)
        {
            w += cost[j - 1][0];
            b += cost[j - 1][1];
        }

        for (lol j = i - x; j >= 0 && j >= i - y; j--)
        {
            if (dp[j][0] != LONG_LONG_MAX)
            {
                dp[i][1] = min(dp[i][1], b + dp[j][0]);
            }
            if (dp[j][1] != LONG_LONG_MAX)
            {
                dp[i][0] = min(dp[i][0], w + dp[j][1]);
            }
            if (j > 0)
            {
                w += cost[j - 1][0];
                b += cost[j - 1][1];
            }
        }
    }
    cout << min(dp[m][0], dp[m][1]);

    return 0;
}