/*
 * @lc app=leetcode id=650 lang=cpp
 *
 * [650] 2 Keys Keyboard
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    int minSteps(int n)
    {
        lol dp[n + 1];
        dp[1] = 0;
        for (lol i = 2; i <= n; i++)
        {
            dp[i] = i;
            for (lol j = i - 1; j >= 2; j--)
            {
                if (i % j == 0)
                {
                    dp[i] = min(dp[i], dp[j] + i / j);
                }
            }
        }
        return dp[n];
    }
};
// @lc code=end
