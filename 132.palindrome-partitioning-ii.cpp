/*
 * @lc app=leetcode id=132 lang=cpp
 *
 * [132] Palindrome Partitioning II
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    bool check(string s)
    {
        lol i = 0;
        lol j = s.size() - 1;
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int minCut(string s)
    {
        lol dp[s.size() + 1];
        for (lol i = 0; i <= s.size(); i++)
        {
            dp[i] = LONG_LONG_MAX;
        }
        bool check[s.size()][s.size()];
        memset(check, false, sizeof(check));
        for (lol i = 0; i < s.size(); i++)
        {
            check[i][i] = true;
        }
        for (lol k = 1; k < s.size(); k++)
        {

            for (lol i = 0, j = k; i < s.size() && j < s.size(); i++, j++)
            {
                if (s[i] == s[j])
                {
                    if (i == j + 1||j==i+1)
                        check[i][j] = true;
                    else
                        check[i][j] = check[i + 1][j - 1];
                }
            }
        }
    

        dp[0] = -1;
        dp[1] = 0;
        for (lol i = 1; i <= s.size(); i++)
        {

            for (lol j = i; j >= 1; j--)
            {
                if (check[j - 1][i - 1])
                {
                    dp[i] = min(dp[i], dp[j - 1] + 1);
                }
            }
        }
        return dp[s.size()];
    }
};
// @lc code=end
