/*
 * @lc app=leetcode id=730 lang=cpp
 *
 * [730] Count Different Palindromic Subsequences
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public: 
    int m=1e9+7;
    int countPalindromicSubsequences(string s)
    {
        long long dp[s.size()][s.size()];
        memset(dp,0,sizeof(dp));
        int next[s.size()];
        int prev[s.size()];
        for (lol i = 0; i < s.size(); i++)
        {
            prev[i] = -1;
            for (lol j = i - 1; j >= 0; j--)
            {
                if (s[i] == s[j])
                {
                    prev[i] = j;
                    break;
                }
            }
            next[i] = -1;
            for (lol j = i + 1; j < s.size(); j++)
            {
                if (s[i] == s[j])
                {
                    next[i] = j;
                    break;
                }
            }
        }
        for (lol k = 0; k < s.size(); k++)
        {
            for (lol i = 0, j = k; i < s.size() && j < s.size(); i++, j++)
            {
                if (i == j)
                {
                    dp[i][j] = 1;
                }
                else if (i == j - 1)
                {

                    dp[i][j] = 2;
                }
                else
                {
                    if (s[i] != s[j])
                    {
                        dp[i][j] = ((dp[i][j - 1] + dp[i + 1][j])%m+m - dp[i + 1][j - 1])%m;
                    }
                    else
                    {
                        if (next[i] > prev[j])
                        {
                            dp[i][j] = ((2 * dp[i + 1][j - 1])%m + 2)%m;
                        }
                        else if (next[i] == prev[j])
                        {
                            dp[i][j] = ((2 * dp[i + 1][j - 1])%m + 1)%m;
                        }
                        else
                        {
                            dp[i][j] = ((2 * dp[i + 1][j - 1])%m+m - dp[next[i]+1][prev[j]-1])%m;
                        }
                    }
                }
            }
        }
        return dp[0][s.size() - 1];
    }
};
// @lc code=end
