/*
 * @lc app=leetcode id=115 lang=cpp
 *
 * [115] Distinct Subsequences
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol unsigned long long
using namespace std;
class Solution
{
public:
    int numDistinct(string s, string t)
    {
        lol dp[t.size() + 1][s.size() + 1];
        for (lol i = 0; i <= s.size(); i++)
        {
            dp[0][i] = 1;
        }
        for (lol i = 1; i <= t.size(); i++)
        {
            dp[i][0] = 0;
        }
        for (lol i = 1; i <= t.size(); i++)
        {
            for (lol j = 1; j <= s.size(); j++)
            {
                dp[i][j] = dp[i][j - 1];
                if (s[j - 1] == t[i - 1])
                    dp[i][j] += dp[i - 1][j - 1];
            }
        }
        return dp[t.size()][s.size()];
    }
};
// @lc code=end
