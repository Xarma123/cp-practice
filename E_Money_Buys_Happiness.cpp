#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol m, x;
        cin >> m >> x;
        pair<lol, lol> a[m];
        lol sum = 0;
        for (lol i = 0; i < m; i++)
        {
            cin >> a[i].first >> a[i].second;
            sum += a[i].second;
        }
        lol dp[m][sum + 1];
        for (lol i = 0; i < m; i++)
        {
            for (lol j = 0; j <= sum; j++)
            {
                if (j == 0)
                {
                    dp[i][j] = 0;
                }
                else if (i == 0)
                {
                    if (a[i].first == 0)
                    {
                        if (j == a[i].second)
                            dp[i][j] = 0;
                        else
                            dp[i][j] = LONG_LONG_MAX;
                    }
                    else
                        dp[i][j] = LONG_LONG_MAX;
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                    if (j >= a[i].second)
                    {
                        lol cost = x * 1ll * (i - 1) - max(a[i].first - x, 0ll);
                        if (dp[i - 1][j - a[i].second] <= cost)
                        {
                            dp[i][j] = min(dp[i][j], dp[i - 1][j - a[i].second] + a[i].first);
                        }
                    }
                }
            }
        }
        lol ans = 0;
        for (lol i = 1; i <= sum; i++)
        {
            if (dp[m - 1][i] != LONG_LONG_MAX)
            {
                ans = i;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
