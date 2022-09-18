/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    int climbStairs(int n)
    {
        lol dp[n + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (lol i = 1; i <= n; i++)
        {
            if (i - 1 >= 0)
                dp[i] += dp[i - 1];
            if (i - 2 >= 0)
                dp[i] += dp[i - 2] ;
        }
        return dp[n];
    }
};
// @lc code=end
