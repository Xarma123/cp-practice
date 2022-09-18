/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
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
        lol dp1[prices.size()];
        lol dp2[prices.size()];
        lol mn = prices[0];
        lol ans = LONG_LONG_MIN;
        for (lol i = 0; i < prices.size(); i++)
        {
            dp1[i] = max(ans, prices[i] - mn);
            ans = max(ans, dp1[i]);
            mn = min(mn, (long long)prices[i]);
        }
        lol mx = prices[prices.size() - 1];
        ans = LONG_LONG_MIN;
        for (lol i = prices.size() - 1; i >= 0; i--)
        {
            dp2[i] = max(ans, mx - prices[i]);
            ans = max(dp2[i], ans);
            mx = max(mx, (long long)prices[i]);
        }
        ans = LONG_LONG_MIN;
        for (lol i = 0; i < prices.size(); i++)
        {
            ans = max(ans, dp1[i] + dp2[i]);
        }
        return ans;
    }
};
// @lc code=end
