#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m, k;
    cin >> n >> m >> k;
    lol c[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> c[i];
        c[i]--;
    }
    lol paint[n][m];
    for (lol i = 0; i < n; i++)
    {
        for (lol j = 0; j < m; j++)
        {
            cin >> paint[i][j];
        }
    }
    lol dp[n][k][m];
    for (lol i = 0; i < n; i++)
    {
        for (lol j = 0; j < k; j++)
        {
            for (lol k1 = 0; k1 < m; k1++)
            {
                dp[i][j][k1] = LONG_LONG_MAX;
            }
        }
    }
    if (c[0] == -1)
    {
        for (lol i = 0; i < m; i++)
        {
            dp[0][0][i] = paint[0][i];
        }
    }
    else
    {
        dp[0][0][c[0]] = 0;
    }
    pair<lol, lol> t[k];
    for (lol i = 0; i < k; i++)
    {
        lol l = LONG_LONG_MAX;
        lol r = LONG_LONG_MAX;
        for (lol j = 0; j < m; j++)
        {
            if (dp[0][i][j] < l)
            {
                r = l;
                l = dp[0][i][j];
            }
            else if (dp[0][i][j] < r)
            {
                r = dp[0][i][j];
            }
        }
        t[i] = {l, r};
    }

    for (lol i = 1; i < n; i++)
    {
        for (lol j = 0; j < k; j++)
        {
            if (c[i] != -1)
            {
                dp[i][j][c[i]] = dp[i - 1][j][c[i]];
                if (j)
                {
                    if (dp[i - 1][j - 1][c[i]] == t[j - 1].first)
                    {
                        dp[i][j][c[i]] = min(dp[i][j][c[i]], t[j - 1].second);
                    }
                    else
                    {
                        dp[i][j][c[i]] = min(dp[i][j][c[i]], t[j - 1].first);
                    }
                }
            }
            else
            {
                for (lol k1 = 0; k1 < m; k1++)
                {
                    dp[i][j][k1] = dp[i - 1][j][k1];
                    if (j)
                    {
                        if (dp[i - 1][j - 1][k1] == t[j - 1].first)
                        {
                            dp[i][j][k1] = min(dp[i][j][k1], t[j - 1].second);
                        }
                        else
                        {
                            dp[i][j][k1] = min(dp[i][j][k1], t[j - 1].first);
                        }
                    }
                    if (dp[i][j][k1] != LONG_LONG_MAX)
                        dp[i][j][k1] += paint[i][k1];
                }
            }
        }
        for (lol j = 0; j < k; j++)
        {

            lol l = LONG_LONG_MAX;
            lol r = LONG_LONG_MAX;
            for (lol k1 = 0; k1 < m; k1++)
            {
                if (dp[i][j][k1] < l)
                {
                    r = l;
                    l = dp[i][j][k1];
                }
                else if (dp[i][j][k1] < r)
                {
                    r = dp[i][j][k1];
                }
            }
            t[j] = {l, r};
        }
    }
    lol ans = LONG_LONG_MAX;
    for (lol i = 0; i < m; i++)
    {
        ans = min(ans, dp[n - 1][k - 1][i]);
    }
    if (ans == LONG_LONG_MAX)
        cout << -1;
    else
        cout << ans;

    return 0;
}