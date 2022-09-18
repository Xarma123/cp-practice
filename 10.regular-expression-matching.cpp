/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        bool dp[s.size() + 1][p.size() + 1];
        dp[0][0] = true;
        for (lol i = 1; i <= p.size(); i++)
        {

            dp[0][i] = false;
            if (p[i - 1] == '*')
            {

                if (i - 2 >= 0)
                    dp[0][i] = dp[0][i - 2];
            }
        }
        for (lol i = 1; i <= s.size(); i++)
        {
            dp[i][0] = false;
        }
        for (lol i = 1; i <= s.size(); i++)
        {
            for (lol j = 1; j <= p.size(); j++)
            {
                dp[i][j] = false;
                if (s[i - 1] == p[j - 1] || p[j - 1] == '.')
                    dp[i][j] |= dp[i - 1][j - 1];
                if (p[j - 1] == '*')
                {
                    if (j - 2 >= 0)
                        dp[i][j] |= dp[i][j - 2];
                    if (i - 1 >= 0)
                    {
                        if (j > 1)
                        {  if(s[i-1]==p[j-2]||p[j-2]=='.')
                            dp[i][j] |= dp[i - 1][j];
                        }
                    }
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};
// @lc code=end
