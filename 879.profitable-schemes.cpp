/*
 * @lc app=leetcode id=879 lang=cpp
 *
 * [879] Profitable Schemes
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    lol m = 1e9 + 7;
    int profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit)
    {
        lol dp[group.size() + 1][n + 1][minProfit + 1];
        memset(dp, 0, sizeof(dp));

        for (lol i = 0; i <= n; i++)
        {
            dp[0][i][0] = 1;
        }
        for (lol i = 1; i <= group.size(); i++)
        {
            for (lol j = 0; j <= n; j++)
            {
                for (lol k = 0; k <= minProfit; k++)
                {
                    dp[i][j][k] += dp[i - 1][j][k];
                    dp[i][j][k] %= m;
                    if (j >= group[i - 1])
                    {
                        dp[i][j][k] += dp[i - 1][j - group[i - 1]][max(0 * 1ll, k - profit[i - 1])];
                        dp[i][j][k] %= m;
                    }
                }
            }
        }
        return dp[group.size()][n][minProfit];
    }
};
// @lc code=end
