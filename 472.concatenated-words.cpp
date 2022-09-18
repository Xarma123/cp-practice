/*
 * @lc app=leetcode id=472 lang=cpp
 *
 * [472] Concatenated Words
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;

class Solution
{
public:
    unordered_set<string> x;
    bool check(string s)
    {
        if (s == "")
            return true;
        for (lol i = 0; i < s.size(); i++)
        {
            if (x.count(s.substr(0, i + 1)))
            {
                if (check(s.substr(i + 1)))
                    return true;
            }
        }
        return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
    {
        vector<string> ans;

        for (lol i = 0; i < words.size(); i++)
        {
            x.insert(words[i]);
        }
        for (lol i = 0; i < words.size(); i++)
        {
            if (words[i] == "")
                continue;
            for (lol j = 0; j < words[i].size() - 1; j++)
            {
                if (x.count(words[i].substr(0, j + 1)))
                {
                    if (check(words[i].substr(j + 1)))
                    {
                        ans.push_back(words[i]);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end
