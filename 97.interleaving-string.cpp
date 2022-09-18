/*
 * @lc app=leetcode id=97 lang=cpp
 *
 * [97] Interleaving String
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        if (s1.size() + s2.size() != s3.size())
            return false;
        bool dp[s1.size() + 1][s2.size() + 1];
        memset(dp, false, sizeof(dp));
        dp[0][0] = true;
        for (lol i = 0; i <= s1.size(); i++)
        {
            for (lol j = 0; j <= s2.size(); j++)
            {
                if (i >= 1)
                {
                    if (s1[i - 1] == s3[i + j - 1])
                    {
                        dp[i][j] |= dp[i - 1][j];
                    }
                }
                if (j >= 1)
                {
                    if (s2[j - 1] == s3[i + j - 1])
                    {
                        dp[i][j] |= dp[i][j - 1];
                    }
                }
            }
        }
        return dp[s1.size()][s2.size()];
    }
};
// @lc code=end
