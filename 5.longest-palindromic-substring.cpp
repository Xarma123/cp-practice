/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    bool is(string s)
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
    string longestPalindrome(string s)
    {
        lol ans = 0;
        string k;
        for (lol i = 0; i < s.size(); i++)
        {
            lol j1 = i - 1, j2 = i + 1;
            if (j1 >= 0 && j2 < s.size())
            {
                while (s[j1] == s[j2])
                {
                    j1--;
                    j2++;
                    if (j1 < 0)
                        break;
                    if (j2 == s.size())
                        break;
                }
            }
            if (ans < j2 - j1 - 1)
            {
                ans = j2 - j1 - 1;
                k = s.substr(j1 + 1, ans);
            }
            j1 = i - 1;
            j2 = i;
            if (j1 >= 0)
            {
                while (s[j1] == s[j2])
                {
                    j1--;
                    j2++;
                    if (!(j1 >= 0 && j2 < s.size()))
                        break;
                }
            }  
            if (ans < j2 - j1 - 1)
            {
                ans = j2 - j1 - 1;
                k = s.substr(j1 + 1, ans);
            }

        } 
        return k;
    }
};
// @lc code=end
