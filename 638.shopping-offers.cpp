/*
 * @lc app=leetcode id=638 lang=cpp
 *
 * [638] Shopping Offers
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    map<vector<int>, lol> mp;
    int shoppingOffers(vector<int> &price, vector<vector<int>> &special, vector<int> needs)
    {
        if (mp.count(needs))
            return mp[needs];
        int ans = 0;
        for (lol i = 0; i < needs.size(); i++)
        {
            ans += needs[i] * price[i];
        }
        for (lol i = 0; i < special.size(); i++)
        {
            bool use = true;
            for (lol j = 0; j < price.size(); j++)
            {
                if (special[i][j] > needs[j])
                    use = false;
            }
            if (use)
            {
                vector<int> x;
                for (lol j = 0; j < needs.size(); j++)
                {
                    x.push_back(needs[j] - special[i][j]);
                }
                ans = min(ans, (shoppingOffers(price, special, x) + special[i][price.size()]));
            }
        }
        mp[needs] = ans;
        return ans;
    }
};
// @lc code=end
