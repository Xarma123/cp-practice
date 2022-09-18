/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    int countSubstrings(string s)
    {
        bool dp[s.size()][s.size()];
        memset(dp, false, sizeof(dp));
        lol ans = 0;
        for (lol i = 0; i < s.size(); i++)
        {
            ans++;
            dp[i][i] = true;
        }
        for (lol k = 1; k < s.size(); k++)
        {
            for (lol i = 0, j = k; i < s.size() && j < s.size(); i++, j++)
            {

                if (s[i] == s[j] && (dp[i + 1][j - 1]||j==i+1))
                {   
                    dp[i][j] = true;
                    ans++;
                }
               
            }
        }
        return ans;
    }
};
// @lc code=end
