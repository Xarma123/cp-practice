/*
 * @lc app=leetcode id=174 lang=cpp
 *
 * [174] Dungeon Game
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        lol n = dungeon.size();
        lol m = dungeon[0].size();
        lol dp[n][m];

        if (dungeon[n - 1][m - 1] >= 0)
            dp[n - 1][m - 1] = 1;
        else
            dp[n - 1][m - 1] = 1 - dungeon[n - 1][m - 1];
        for (lol i = n - 1; i >= 0; i--)
        {
            for (lol j = m - 1; j >= 0; j--)
            {
                if (i + 1 < n && j + 1 < m)
                {
                    dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
                }
                else if (i + 1 < n)
                {
                    dp[i][j] = dp[i + 1][j] - dungeon[i][j];
                }
                else if (j + 1 < m)
                {
                    dp[i][j] = dp[i][j + 1] - dungeon[i][j];
                }
                if (dp[i][j] <= 0)
                    dp[i][j] = 1;
            }
        }
        return dp[0][0];
    }
};
// @lc code=end
