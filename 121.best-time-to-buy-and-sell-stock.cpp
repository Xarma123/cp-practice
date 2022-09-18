/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
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
        lol ans = LONG_LONG_MIN;
        lol mn = prices[0];
        for (lol i = 1; i < prices.size(); i++)
        {
            ans = max(ans,prices[i]-mn);
            mn = min(mn, (long long)prices[i]);
        }
        if (ans <= 0)
            return 0;
        else
            return ans;
    }
};
// @lc code=end
