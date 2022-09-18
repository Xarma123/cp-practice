/*
 * @lc app=leetcode id=514 lang=cpp
 *
 * [514] Freedom Trail
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    map<pair<lol, lol>, lol> mp;
    lol solve(string ring, string key, lol ind, lol t)
    {
        if (t == key.size())
            return 0;

        if (!mp.count({ind, t}))
        {

            lol ans = LONG_LONG_MAX;
            for (lol i = 0; i < ring.size(); i++)
            {
                if (ring[i] == key[t])
                {
                    lol n = ring.size();
                    lol v = abs(ind - i);
                    ans = min(ans, min(v, n - v) + 1 + solve(ring, key, i, t + 1));
                    cout << ans << " " << ring[i] << endl;
                }
            }
            mp[{ind, t}] = ans;
        }
        return mp[{ind, t}];
    }
    int findRotateSteps(string ring, string key)
    {
        return solve(ring, key, 0, 0);
    }
};
// @lc code=end
