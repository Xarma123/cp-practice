/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        lol s = 0;
        lol n = nums.size();
        for (lol i = 0; i < n; i++)
        {
            s += nums[i];
        }
        if (s % 2 != 0)
            return false;
        s /= 2;
        bool dp[s + 1][n + 1];
        for (lol i = 0; i <= n; i++)
        {
            dp[0][i] = true;
        }
        for (lol i = 1; i <= s; i++)
        {
            dp[i][0] = false;
        }
        for (lol i = 1; i <= s; i++)
        {
            for (lol j = 1; j <= n; j++)
            {
                dp[i][j] = dp[i][j - 1];
                if (i - nums[j - 1] >= 0)
                {
                    dp[i][j] |= dp[i - nums[j - 1]][j-1];
                }
            }
        }
        return dp[s][n];
    }
};
// @lc code=end
