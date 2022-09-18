/*
 * @lc app=leetcode id=312 lang=cpp
 *
 * [312] Burst Balloons
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    int maxCoins(vector<int> &nums)
    {
        lol n = nums.size();
        lol dp[n][n];
        memset(dp, 0, sizeof(dp));
        for (lol k = 0; k < n; k++)
        {
            for (lol i = 0, j = k; i < n && j < n; i++, j++)
            {
                if (i == j)
                {
                    dp[i][j] = nums[i];
                    if (i - 1 >= 0)
                        dp[i][j] *= nums[i - 1];
                    if (i + 1 < n)
                        dp[i][j] *= nums[i + 1];
                }
                else
                {
                    for (lol l = i; l <= j; l++)
                    {
                        lol x = nums[l];
                        if (i - 1 >= 0)
                            x *= nums[i - 1];
                        if (j + 1 < n)
                            x *= nums[j + 1];
                        if (l - 1 >= 0 && l + 1 < n)
                            dp[i][j] = max(dp[i][j], x + dp[i][l - 1] + dp[l + 1][j]);
                        else if (l - 1 >= 0)
                            dp[i][j] = max(dp[i][j], x + dp[i][l - 1]);
                        else if (l + 1 < n)
                        {
                            dp[i][j] = max(dp[i][j], x + dp[l + 1][j]);
                        }
                        else
                            dp[i][j] = max(dp[i][j], x);
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};
// @lc code=end
