/*
 * @lc app=leetcode id=629 lang=cpp
 *
 * [629] K Inverse Pairs Array
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol m = 1e9 + 7;
class Solution
{
public:
    int kInversePairs(int n, int k)
    {
        lol dp[k + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        for (lol i = 0; i <= n; i++)
        {
            dp[0][i] = 1;
        }
        for (lol i = 2; i <= n; i++)
        {
            for (lol j = 1; j <= k; j++)
            {
                dp[j][i] += dp[j][i - 1];
                dp[j][i] %= m;
                if (j - i >= 0)
                {
                    dp[j][i] = ((dp[j - 1][i] - dp[j - i][i - 1] + m) % m + dp[j][i]) % m;
                }
                else
                    dp[j][i] += dp[j - 1][i];
                dp[j][i] %= m;
            }
        }
        return dp[k][n];
    }
};
// @lc code=end
