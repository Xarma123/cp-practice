/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        lol dp[2][nums.size()];
        dp[0][0] = 0;
        dp[1][0] = nums[0];
        for (lol i = 1; i < nums.size(); i++)
        {
            dp[0][i] = max(dp[0][i - 1], dp[1][i - 1]);
            dp[1][i] = nums[i] + dp[0][i - 1];
        } 
        return max(dp[0][nums.size()-1],dp[1][nums.size()-1]);
    }
};
// @lc code=end
