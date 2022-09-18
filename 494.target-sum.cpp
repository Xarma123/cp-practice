/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        lol n = nums.size();
        lol S = 0;
        for (lol i = 0; i < n; i++)
        {
            S += nums[i];
        }
        if (target < 0)
            target = -target;
        if ((S + target) % 2 != 0)
            return 0;
        lol T = (S + target) / 2;

        lol dp[T + 1][n + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (lol i = 1; i <= n; i++)
        {
            dp[0][i] += dp[0][i - 1];
            if (0 - nums[i - 1] >= 0)
                dp[0][i] += dp[0 - nums[i - 1]][i - 1];
        }
        for (lol i = 1; i <= T; i++)
        {
            dp[i][0] = 0;
        }
        for (lol i = 1; i <= T; i++)
        {
            for (lol j = 1; j <= n; j++)
            {
                dp[i][j] += dp[i][j - 1];
                if (i - nums[j - 1] >= 0)
                    dp[i][j] += dp[i - nums[j - 1]][j - 1];
            }
        }
        return dp[T][n];
    }
};
// @lc code=end
