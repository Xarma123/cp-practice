/*
 * @lc app=leetcode id=467 lang=cpp
 *
 * [467] Unique Substrings in Wraparound String
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    int findSubstringInWraproundString(string p)
    {
        lol n = p.size();
        lol ans = 0;
        map<char, lol> mp;
        for (lol i = 0; i < n; i++)
        {

            lol j = i + 1;
            mp[p[j - 1]] = max(mp[p[j - 1]], j - i);

            if (j < n)
            {
                while ((p[j - 1] == 'z' && p[j] == 'a') || (p[j] == p[j - 1] + 1))
                {

                    j++;
                    mp[p[j - 1]] = max(mp[p[j - 1]], j - i);

                    if (j == n)
                        break;
                }
            }

            i = j - 1;
        }
        for (auto i = mp.begin(); i != mp.end(); i++)
        {
            ans += (*i).second;
        }

        return ans;
    }
};
// @lc code=end
