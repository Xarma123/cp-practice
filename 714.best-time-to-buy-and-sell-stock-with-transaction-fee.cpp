/*
 * @lc app=leetcode id=714 lang=cpp
 *
 * [714] Best Time to Buy and Sell Stock with Transaction Fee
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        int dp[2][n];
        dp[0][0] = 0;
        dp[1][0] = -fee;
        int mx = dp[0][0]-fee-prices[0];
        for (lol i = 1; i < n; i++)
        {
            dp[0][i] = max(dp[0][i - 1], dp[1][i - 1]);
            dp[1][i] = -fee; 

           
                dp[1][i] = max(dp[1][i], prices[i] +mx); 
            mx=max(mx,dp[0][i]-fee-prices[i]);
            
        } 
        return max(dp[0][n-1],dp[1][n-1]);
    }
};
// @lc code=end
