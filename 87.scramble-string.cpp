/*
 * @lc app=leetcode id=87 lang=cpp
 *
 * [87] Scramble String
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    map<pair<string, string>, bool> mp;
    bool isScramble(string s1, string s2)
    {
        if (mp.count({s1, s2}))
            return mp[{s1, s2}];

        if (s1 == s2)
            return true;

        if (s1.size() != s2.size())
            return false;
        if (s1.size() == 0)
            return true;
        lol c[27];
        memset(c, 0, sizeof(c));
        map<char, lol> c1[s1.size() + 1];
        map<char, lol> c2[s2.size() + 1];
        for (lol i = 1; i <= s1.size(); i++)
        {
            c1[i][s1[i - 1]]++;
            for (char z = 'a'; z <= 'z'; z++)
            {
                c1[i][z] += c1[i - 1][z];
            }
        }
        for (lol i = 1; i <= s1.size(); i++)
        {
            c2[i][s2[i - 1]]++;
            for (char z = 'a'; z <= 'z'; z++)
            {
                c2[i][z] += c2[i - 1][z];
            }
        }

        for (lol i = 0; i < s1.size(); i++)
        {
            c[s1[i] - 'a']++;
            c[s2[i] - 'a']--;
        }
        for (lol i = 0; i < 27; i++)
        {
            if (c[i] != 0)
                return false;
        }
        for (lol i = 0; i < s1.size() - 1; i++)
        {
            bool f = true, f2 = true;
            for (char z = 'a'; z <= 'z'; z++)
            {
                if (c1[i + 1][z] != c2[i + 1][z])
                    f = false;

                if (c1[i + 1][z] != c2[s2.size()][z] - c2[s2.size() - i - 1][z])
                    f2 = false;
            }

            if (f)
                if (isScramble(s1.substr(0, i + 1), s2.substr(0, i + 1)) && isScramble(s1.substr(i + 1), s2.substr(i + 1)))
                {
                    mp[{s1, s2}] = true;
                    return true;
                }
            if (f2)
                if (isScramble(s1.substr(0, i + 1), s2.substr(s2.size() - i - 1)) && isScramble(s1.substr(i + 1), s2.substr(0, s2.size() - i - 1)))
                {
                    mp[{s1, s2}] = true;
                    return true;
                }
        }
        mp[{s1, s2}] = false;
        return false;
    }
};
// @lc code=end
