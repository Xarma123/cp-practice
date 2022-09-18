/*
 * @lc app=leetcode id=466 lang=cpp
 *
 * [466] Count The Repetitions
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2)
    {

        lol cp = 0;
        lol c = 0;
        map<lol, pair<lol, lol>> mp;
        while (n1--)
        {
            if (!mp.count(cp))
            {
                lol cur = 0;
                lol p = cp;
                for (lol i = 0; i < s1.size(); i++)
                {
                    if (s2[p] == s1[i])
                        p++;
                    if (p == s2.size())
                    {
                        cur++;
                        p = 0;
                    }
                }
                mp[cp] = {cur, p};
            }
            c += mp[cp].first;
            cp = mp[cp].second;
        }
        return c / n2;
    }
};
// @lc code=end
