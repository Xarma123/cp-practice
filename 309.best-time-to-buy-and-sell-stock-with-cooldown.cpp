/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        lol dp[3][prices.size()];
        dp[0][0] = -prices[0]; // bought
        dp[1][0] = 0;          // sold
        dp[2][0] = 0;          // cool
        for (lol i = 1; i < prices.size(); i++)
        {
            dp[0][i] = max(dp[0][i - 1], dp[2][i - 1] - prices[i]);
            dp[1][i] = dp[0][i - 1] + prices[i];
            dp[2][i] = max(dp[1][i - 1], dp[2][i - 1]);
        }
        lol ans = LONG_LONG_MIN;
        for (lol i = 0; i < prices.size(); i++)
        {
            ans = max(ans, max(dp[0][i], dp[1][i]));
            ans = max(ans, dp[2][i]);
        }
        return ans;
    }
};
// @lc code=end
