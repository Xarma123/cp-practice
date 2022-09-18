/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        lol p = 0;
        for (lol i = 0; i < t.size(); i++)
        {
            if (p == s.size())
                break;
            if (t[i] == s[p])
                p++;
        }
        return p == s.size();
    }
};
// @lc code=end
