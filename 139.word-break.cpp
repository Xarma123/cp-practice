/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> mp;
        for (lol i = 0; i < wordDict.size(); i++)
        {
            mp.insert(wordDict[i]);
        }
        bool dp[s.size() + 1];
        memset(dp, false, sizeof(dp));
        dp[0] = true;
        for (lol i = 0; i < s.size(); i++)
        {
            for (lol j = i; j >= 0; j--)
            {
                if (mp.count(s.substr(j, i - j + 1)))
                {
                    dp[i + 1] |= dp[j];
                }
            }
        }
        return dp[s.size()];
    }
};
// @lc code=end
