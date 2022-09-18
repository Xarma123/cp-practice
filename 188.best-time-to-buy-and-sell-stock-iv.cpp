/*
 * @lc app=leetcode id=188 lang=cpp
 *
 * [188] Best Time to Buy and Sell Stock IV
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        if (prices.size() == 0)
            return 0;
        lol dp[k + 1][prices.size()];
        for (lol i = 0; i < prices.size(); i++)
        {
            dp[0][i] = 0;
        }
        for (lol i = 0; i <= k; i++)
        {
            dp[i][0] = 0;
        }
        lol mx[prices.size()];
        for (lol i = 0; i <= k; i++)
        {
            for (lol j = 0; j < prices.size(); j++)
            {
                if (i > 0)
                    dp[i][j] = max(mx[j] + prices[j], dp[i - 1][j]);
                if (j > 0)
                    dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            }
            mx[0] = dp[i][0] - prices[0];
            for (lol j = 1; j < prices.size(); j++)
            {
                mx[j] = max(dp[i][j] - prices[j], mx[j - 1]);
            }
        }
        return dp[k][prices.size() - 1];
    }
};
// @lc code=end
