/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        lol dp[m][n];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (lol i = 0; i < m; i++)
        {
            for (lol j = 0; j < n; j++)
            {

                if (i - 1 >= 0)
                    dp[i][j] += dp[i - 1][j];
                if (j - 1 >= 0)
                    dp[i][j] += dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};
// @lc code=end
