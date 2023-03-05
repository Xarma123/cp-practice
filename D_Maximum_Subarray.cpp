#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, k, x;
        cin >> n >> k >> x;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol dp[n][k + 1];
        for (lol i = 0; i < n; i++)
        {
            if (i == 0)
            {
                dp[i][0] = a[i] - x;
                dp[i][0] = max(dp[i][0], 0ll);
                for (lol j = 1; j <= k; j++)
                {
                    if (j == 1)
                        dp[i][j] = a[i] + x;
                    else
                        dp[i][j] = LONG_LONG_MIN;
                    if (dp[i][j] != LONG_LONG_MIN)
                        dp[i][j] = max(dp[i][j], 0ll);
                }
            }
            else
            {
                for (lol j = 0; j <= k; j++)
                {
                    dp[i][j] = LONG_LONG_MIN;
                    if (dp[i - 1][j] != LONG_LONG_MIN)
                    {
                        dp[i][j] = max(dp[i][j], dp[i - 1][j] + a[i] - x);
                        dp[i][j] = max(dp[i][j], a[i] - x);
                    }
                    if (j)
                    {
                        if (dp[i - 1][j - 1] != LONG_LONG_MIN)
                        {
                            dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + a[i] + x);
                            dp[i][j] = max(dp[i][j], a[i] + x);
                        }
                    }
                    if (dp[i][j] != LONG_LONG_MIN)
                        dp[i][j] = max(dp[i][j], 0ll);
                }
            }
        }
        lol ans = LONG_LONG_MIN;
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j <= k; j++)
            {
                if (j + n - (i + 1) >= k)
                    ans = max(ans, dp[i][j]);
            }
        }
        cout << ans << '\n';
    }

    return 0;
}