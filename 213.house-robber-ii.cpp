/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    int rob(vector<int> &nums)
    {   if(nums.size()==1)
        return nums[0];
        lol ans = LONG_LONG_MIN;
        lol dp[2][nums.size() - 1];
        for (lol k = 0; k < nums.size(); k++)
        {

            dp[0][0] = 0;
            dp[1][0] = nums[(k + 1) % nums.size()];
            lol p = (k + 2) % nums.size();
            for (lol i = 1; i < nums.size() - 1; i++)
            {
                lol j = i - 1;

                dp[0][i] = max(dp[0][j], dp[1][j]);
                dp[1][i] = nums[p] + dp[0][j];
                p++;
                p %= nums.size();
            }
            ans = max(ans, max(dp[0][nums.size() - 2], dp[1][nums.size() - 2]));
        } 
        return ans;
    }
};
// @lc code=end
