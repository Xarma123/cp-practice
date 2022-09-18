#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m, K;
    cin >> n >> m >> K;
    lol c[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    lol p[n][m];
    for (lol i = 0; i < n; i++)
    {
        for (lol j = 0; j < m; j++)
        {
            cin >> p[i][j];
        }
    }
    lol dp[n + 1][m][K + 1];
    vector<pair<lol, lol>> pre;
    for (lol i = 0; i <= n; i++)
    {

        for (lol j = 0; j < m; j++)
        {

            for (lol k = 0; k <= K; k++)
            {
                if (i == 0)
                {
                    if (k == 0)
                        dp[i][j][k] = 0;
                    else
                    {
                        dp[i][j][k] = LONG_LONG_MAX;
                    }
                }
                else if (k == 0)
                {
                    dp[i][j][k] = LONG_LONG_MAX;
                }
                else
                {
                    if (c[i - 1] != 0)
                    {
                        dp[i][j][k] = LONG_LONG_MAX;
                        if (c[i - 1] != j + 1)
                            continue;
                        if (i == 1)
                        {
                            if (k == 1)
                                dp[i][j][k] = 0;
                            else
                                dp[i][j][k] = LONG_LONG_MAX;
                        }
                        else if (pre[k - 1].first != dp[i - 1][j][k - 1])
                        {
                            dp[i][j][k] = min(dp[i][j][k], pre[k - 1].first);
                        }
                        else
                        {
                            dp[i][j][k] = min(dp[i][j][k], pre[k - 1].second);
                        }
                        dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k]);
                    }
                    else
                    {
                        dp[i][j][k] = LONG_LONG_MAX;
                        if (i == 1)
                        {
                            if (k == 1)
                                dp[i][j][k] = min(dp[i][j][k], p[i - 1][j]);
                            else
                            {
                                dp[i][j][k] = LONG_LONG_MAX;
                            }
                        }
                        else if (pre[k - 1].first != dp[i - 1][j][k - 1])
                        {
                            if (pre[k - 1].first != LONG_LONG_MAX)
                                dp[i][j][k] = min(dp[i][j][k], pre[k - 1].first + p[i - 1][j]);
                        }
                        else
                        {
                            if (pre[k - 1].second != LONG_LONG_MAX)
                                dp[i][j][k] = min(dp[i][j][k], pre[k - 1].second + p[i - 1][j]);
                        }
                        if (dp[i - 1][j][k] != LONG_LONG_MAX)
                            dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k] + p[i - 1][j]);
                    }
                }
            }
        }
        pre.clear();
        for (lol k = 0; k <= K; k++)
        {
            lol f = LONG_LONG_MAX, s = LONG_LONG_MAX;
            for (lol j = 0; j < m; j++)
            {
                if (dp[i][j][k] <= f)
                {
                    s = f;
                    f = dp[i][j][k];
                }
                else if (dp[i][j][k] <= s)
                {
                    s = dp[i][j][k];
                }
            }
            pre.push_back({f, s});
        }
    }
    lol ans = LONG_LONG_MAX;
    for (lol i = 0; i < m; i++)
    {
        ans = min(ans, dp[n][i][K]);
    }
    if (ans == LONG_LONG_MAX)
        cout << -1;
    else
        cout << ans;

    return 0;
}