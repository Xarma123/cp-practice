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
    for (lol i = 0; i < n; i++)
    {
        cin >> w[i] >> v[i];
    }
    lol dp[W + 1][n + 1];
    for (lol i = 0; i <= W; i++)
    {
        for (lol j = 0; j <= n; j++)
        {
            if (i == 0)
                dp[i][j] = 0;
            else if (j == 0)
                dp[i][j] = 0;
            else
            {
                dp[i][j] = dp[i][j - 1];
                if (i - w[j - 1] >= 0)
                    dp[i][j] = max(dp[i - w[j - 1]][j - 1] + v[j - 1], dp[i][j]);
            }
        }
    }
    cout << dp[W][n];

    return 0;
}