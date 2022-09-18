/*
 * @lc app=leetcode id=576 lang=cpp
 *
 * [576] Out of Boundary Paths
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
    lol dp[100][100][100];
    lol M = 1e9 + 7;

    lol solve(lol m, lol n, lol x, lol y, lol move)
    {
        if (dp[x][y][move] != -1)
            return dp[x][y][move];

        lol ans = 0;

        if (move <= 0)
            return 0;
        if (x - 1 < 0)
            ans++;
        else
        {

            ans += solve(m, n, x - 1, y, move - 1);
        }
        ans %= M;
        if (x + 1 >= m)
            ans++;
        else
        {

            ans += solve(m, n, x + 1, y, move - 1);
        }
        ans %= M;
        if (y - 1 < 0)
            ans++;
        else
        {

            ans += solve(m, n, x, y - 1, move - 1);
        }
        ans %= M;
        if (y + 1 >= n)
            ans++;
        else
        {

            ans += solve(m, n, x, y + 1, move - 1);
        }
        ans %= M;
        dp[x][y][move] = ans;
        return ans;
    }

public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        memset(dp, -1, sizeof(dp));
        return solve(m, n, startRow, startColumn, maxMove);
    }
};
// @lc code=end
