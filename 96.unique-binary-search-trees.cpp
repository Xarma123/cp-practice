/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    int numTrees(int n)
    {
        lol dp[2 * n + 1][2 * n + 1];
        for (lol i = 0; i < 2 * n + 1; i++)
        {
            dp[i][0] = 1;
        }
        for (lol i = 1; i < 2 * n + 1; i++)
        {
            for (lol j = 1; j < 2 * n + 1 && j <= i; j++)
            {
                if (i != j)
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
                else
                    dp[i][j] = 1;
            }
        }
        return dp[2 * n][n]/(n+1);
    }
};
// @lc code=end
