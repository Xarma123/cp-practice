/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    int numSquares(int n)
    {
        lol dp[n + 1];
        for (lol i = 0; i <= n; i++)
        {
            dp[i] = LONG_LONG_MAX;
        }

        dp[0] = 0;
        for (lol i = 1; i <= n; i++)
        {
            for (lol j = 1; j * j <= i; j++)
            {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};
// @lc code=end
