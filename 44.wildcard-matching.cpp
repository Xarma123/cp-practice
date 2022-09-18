/*
 * @lc app=leetcode id=44 lang=cpp
 *
 * [44] Wildcard Matching
 */

// @lc code=start,
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        lol dp[s.size() + 1][p.size() + 1];
        dp[0][0] = true;
        for (lol i = 1; i <= p.size(); i++)
        {

            dp[0][i] = dp[0][i - 1];
            if (p[i - 1] != '*')
                dp[0][i] = false;
        }
        bool c[p.size() + 1];
        for (lol i = 1; i <= s.size(); i++)
        {
            dp[i][0] = false;
        }
        for (lol i = 1; i <= s.size(); i++)
        {
            for (lol j = 1; j <= p.size(); j++)
            {
                dp[i][j] = false;
                if (p[j - 1] != '*' && p[j - 1] != '?')
                {
                    if (s[i - 1] == p[j - 1])
                    {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                }
                else if (p[j - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];
                else
                {
                    dp[i][j] |= dp[i][j - 1];
                    dp[i][j] |= dp[i - 1][j];

                }
            }
        } 
        return dp[s.size()][p.size()];
    }
};
// @lc code=end
