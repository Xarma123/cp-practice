/*
 * @lc app=leetcode id=664 lang=cpp
 *
 * [664] Strange Printer
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    int strangePrinter(string s)
    {
        lol n = s.size();
        lol dp[n][n];

        for (lol k = 0; k < n; k++)
        {
            for (lol i = 0, j = k; i < n & j < n; i++, j++)
            {
                if (i == j)
                    dp[i][j] = 1;
                else if (i == j - 1)
                {
                    if (s[i] == s[j])
                        dp[i][j] = 1;
                    else
                        dp[i][j] = 2;
                }
                else
                {
                    lol v = LONG_LONG_MAX;
                    for (lol q = i; q <j ; q++)
                    {
                        v = min(dp[i][q] + dp[q+1][j], v);
                    }
                    if (s[i] == s[j])
                        v--;
                    dp[i][j] = v;
                }
            }
        }
        return dp[0][n - 1];
    }
};
// @lc code=end
