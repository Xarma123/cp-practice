/*
 * @lc app=leetcode id=516 lang=cpp
 *
 * [516] Longest Palindromic Subsequence
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        string j = s;
        reverse(j.begin(), j.end());
        lol n = j.size();
        lol dp[n + 1][n + 1];
        for (lol i = 0; i <= n; i++)
        {
            dp[0][i] = 0;
            dp[i][0] = 0;
        }
        for (lol i = 1; i <= n; i++)
        {
            for (lol j1 = 1; j1 <= n; j1++)
            {
                dp[i][j1] = max(dp[i - 1][j1], dp[i][j1 - 1]);
                if (s[i - 1] == j[j1 - 1])
                {
                    dp[i][j1] = max(dp[i][j1], dp[i - 1][j1 - 1] + 1);
                }
            }
        }
        return dp[n][n];
    }
};
// @lc code=end
