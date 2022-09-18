/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        lol dp[amount + 1];
        for (lol i = 0; i <= amount; i++)
        {
            dp[i] = INT_MAX;
        }

        dp[0] = 0;
        for (lol i = 1; i <= amount; i++)
        {

            for (lol j = 0; j < coins.size(); j++)
            {
                lol v = coins[j];
                lol c = 1;

                if (v <= i)
                {
                    if (dp[i - v] != INT_MAX)
                        dp[i] = min(dp[i], c + dp[i - v]);

                   
                }
            }
        }
        if (dp[amount] == INT_MAX)
            return -1;
        return dp[amount];
    }
};
// @lc code=end
