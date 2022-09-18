/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    map<string, lol> mp;
    int numDecodings(string s)
    {
        if (mp.count(s))
            return mp[s];
        if (s[0] == '0')
            mp[s] = 0;
        else if (s.size() <= 1)
            mp[s] = 1;

        else if (s.size() >= 2)
        {
            string z = s.substr(0, 2);
            if (1 <= stoll(z) && stoll(z) <= 26)
            {
                mp[s] = numDecodings(s.substr(1)) + numDecodings(s.substr(2));
            }
            else
                mp[s] = numDecodings(s.substr(1));
        }
        else
            mp[s] = numDecodings(s.substr(1));
        return mp[s];
    }
};
// @lc code=end
