#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, W;
    cin >> n >> W;
    lol w[n], v[n];
    lol V = 0;
    for (lol i = 0; i < n; i++)
    {
        cin >> w[i] >> v[i];
        V += v[i];
    }
    lol dp[V + 1][n + 1];
    lol ans = 0;
    for (lol i = 0; i <= V; i++)
    {
        for (lol j = 0; j <= n; j++)
        {
            if (i == 0)
                dp[i][j] = 0;
            else if (j == 0)
                dp[i][j] = LONG_LONG_MAX;
            else
            {
                dp[i][j] = dp[i][j - 1];
                if (i - v[j - 1] >= 0 && dp[i - v[j - 1]][j - 1] != LONG_LONG_MAX)
                {
                    dp[i][j] = min(dp[i][j], dp[i - v[j - 1]][j - 1] + w[j - 1]);
                }
            }
            if (dp[i][j] <= W)
                ans = i;
        }
    }
    cout << ans;

    return 0;
}