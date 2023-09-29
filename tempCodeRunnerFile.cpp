#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    lol dp[n][2001];
    lol ans = 0;
    for (lol i = 0; i < n; i++)
    {
        if (i == 0)
        {
            for (lol j = 0; j < 2001; j++)
            {
                dp[i][j] = 0;
            }
            dp[i][a[i]] = 1;
        }
        else
        {
            for (lol j = 0; j < 2001; j++)
            {
                dp[i][j] = dp[i - 1][j];
            }
            dp[i][a[i]] = max(dp[i][a[i]], 1ll);
            if (a[i] % 3 == 0)
            {
                dp[i][a[i]] = max(dp[i][a[i]], dp[i - 1][(a[i] / 3)] + 1);
            }
        }
    }
    for (lol j = 0; j < 2001; j++)
    {
        ans = max(ans, dp[n - 1][j]);
    }
    cout << ans;
}