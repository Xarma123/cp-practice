/*
 * @lc app=leetcode id=691 lang=cpp
 *
 * [691] Stickers to Spell Word
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    string cmp(string a, string b)
    {
        map<char, lol> mp;
        for (lol i = 0; i < a.size(); i++)
        {
            mp[a[i]]++;
        }
        for (lol i = 0; i < b.size(); i++)
        {
            if (mp.count(b[i]))
            {
                mp[b[i]]--;
                b.erase(i, 1);

                if (mp[b[i] == 0])
                    mp.erase(b[i]);
                i--;
            }
        }
        sort(b.begin(), b.end());
        return b;
    }
    int minStickers(vector<string> &stickers, string target)
    {
        int w = -1;
        if (target == "")
            return 0;
        for (lol i = 0; i < stickers.size(); i++)
        {
            string q = cmp(stickers[i], target);
            if (q.size() < target.size())
            {

                int t = minStickers(stickers, q);
                if (t != -1)
                {
                    if (w == -1)
                        w = t;
                    else
                        w = min(w, 1 + t);
                }
            }
        }
        return w;
    }
};
// @lc code=end
