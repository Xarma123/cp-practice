#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, k, d;
    cin >> n >> k >> d;
    lol m = 1e9 + 7;
    lol dp[n + 1][2];
    dp[0][0] = 1;
    dp[0][1] = 0;

    for (int i = 1; i <= n; ++i)
    {
        dp[i][0] = dp[i][1] = 0;

        for (int j = 1; j <= k; ++j)
        {
            if (i - j < 0)
                break;

            if (j < d)
            {
                dp[i][0] += dp[i - j][0];
                dp[i][0] %= m;

                dp[i][1] += dp[i - j][1];
                dp[i][1] %= m;
            }
            else
            {
                dp[i][1] += dp[i - j][0];
                dp[i][1] %= m;
                dp[i][1] += dp[i - j][1];
                dp[i][1] %= m;
            }
        }
    }
    cout << dp[n][1] << "\n";
    return 0;
}
