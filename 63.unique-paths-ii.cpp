/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        lol m = obstacleGrid.size();
        lol n = obstacleGrid[0].size();
        lol dp[m][n];
        memset(dp, 0, sizeof(dp));
        if(!obstacleGrid[0][0])
        dp[0][0] = 1;
        for (lol i = 0; i < m; i++)
        {
            for (lol j = 0; j < n; j++)
            {
                if (obstacleGrid[i][j])
                {
                    continue;
                }

                if (i - 1 >= 0)
                {   
                    dp[i][j] += dp[i - 1][j];
                }
                if (j - 1 >= 0)
                {
                    dp[i][j] += dp[i][j - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
// @lc code=end
