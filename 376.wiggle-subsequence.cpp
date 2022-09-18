/*
 * @lc app=leetcode id=376 lang=cpp
 *
 * [376] Wiggle Subsequence
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        lol dp[2][nums.size()];
        dp[0][0] = 1;
        dp[1][0] = 1;
        lol ans = 1;
        for (lol i = 1; i < nums.size(); i++)
        {
            dp[0][i] = 1;
            dp[1][i] = 1;
            lol v1 = 0;
            lol v2 = 0;
            for (lol j = i - 1; j >= 0; j--)
            {
                if (nums[j] < nums[i])
                {
                    v1 = max(v1, dp[0][j]);
                }
                else if (nums[j] > nums[i])
                {
                    v2 = max(v2, dp[1][j]);
                }
            }
            dp[0][i] += v2;
            dp[1][i] += v1;
            ans = max(ans, max(dp[0][i], dp[1][i]));
        }
        return ans;
    }
};
// @lc code=end
