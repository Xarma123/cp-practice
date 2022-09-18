#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m, t;
    cin >> n >> m >> t;
    lol q = max(n, m);
    lol dp[q + 1][q + 1];
    for (lol i = 0; i <= q; i++)
    {
        for (lol j = 0; j <= q; j++)
        {
            if (i == j)
                dp[i][j] = 1;
            else if (i < j)
                dp[i][j] = -1;
            else if (j == 0)
                dp[i][j] = 1;
            else if (j == 1)
                dp[i][j] = i;
            else
            {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
            }
        }
    }
    lol ans = 0;
    for (lol i = 4; t - i >= 1; i++)
    {
        if (i <= n && t - i <= m)
            ans += dp[n][i] * 1ll * dp[m][t - i];
    }
    cout << ans;

    return 0;
}