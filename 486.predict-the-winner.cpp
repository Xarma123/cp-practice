/*
 * @lc app=leetcode id=486 lang=cpp
 *
 * [486] Predict the Winner
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    bool PredictTheWinner(vector<int> &nums)
    {
        lol n = nums.size();
        lol dp[n][n];
        for (lol k = 0; k < n; k++)
        {
            for (lol i = 0, j = k; i < n && j < n; i++, j++)
            {
                if (i == j)
                    dp[i][j] = nums[i];
                else
                {
                    dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
                }
            }
        }

        return dp[0][n - 1] >= 0;
    }
};
// @lc code=end
