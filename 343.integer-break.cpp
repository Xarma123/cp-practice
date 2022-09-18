/*
 * @lc app=leetcode id=343 lang=cpp
 *
 * [343] Integer Break
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    int integerBreak(int n)
    {
        lol dp[n + 1];
        for (lol i = 0; i <= n; i++)
        {
            dp[i] = LONG_LONG_MIN;
        }

        dp[1] = 1;
        dp[2] = 1;
        for (lol i = 3; i <= n; i++)
        {
            for (lol j = 1; i - j >= 1; j++)
            {
                dp[i] = max(dp[i], j * dp[i - j]);
                dp[i]=max(dp[i],i*j-j*j);
            }
            cout << dp[i] << " ";
        }
        return dp[n];
    }
};
// @lc code=end
