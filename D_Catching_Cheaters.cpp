#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    lol dp[n + 1][m + 1];
    lol ans = 0;
    memset(dp, 0, sizeof(dp));
    for (lol i = 1; i <= n; i++)
    {
        for (lol j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = 2 + max(dp[i - 1][j - 1], 0ll);
            }
            dp[i][j] = max(dp[i][j], max(dp[i][j - 1], dp[i - 1][j]) - 1);
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans;
}