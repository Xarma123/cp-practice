/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.size() == 0)
            return 0;
        map<char, lol> mp;
        lol ans = 1;
        lol l = 0;
        mp[s[0]]++;
        for (lol i = 1; i < s.size(); i++)
        {
            mp[s[i]]++;
            if (mp[s[i]] >= 2)
            {
                while (mp[s[i]] != 1)
                {
                    mp[s[l]]--;
                    l++;
                }
            }

            ans = max(ans, (i - l + 1));
        }
        return ans;
    }
};
// @lc code=end
