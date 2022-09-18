/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> mp;
        for (lol i = 0; i < wordDict.size(); i++)
        {
            mp.insert(wordDict[i]);
        }
        vector<string> dp[s.size() + 1];
        for (lol i = 0; i < s.size(); i++)
        {
            for (lol j = i; j >= 0; j--)
            {
                string q = s.substr(j, i - j + 1);
                if (mp.count(q))
                {
                    if (j == 0)
                        dp[i+1].push_back(q);
                    for (lol k = 0; k < dp[j].size(); k++)
                    {   
                        dp[i+1].push_back((dp[j][k] + " " + q));
                    }
                }
            }
        }
        return dp[s.size()];
    }
};
// @lc code=end
