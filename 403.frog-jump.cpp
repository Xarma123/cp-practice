/*
 * @lc app=leetcode id=403 lang=cpp
 *
 * [403] Frog Jump
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    bool canCross(vector<int> &stones)
    {
        lol n = stones.size();
        unordered_set<lol> dp[n];

        dp[0].insert(1);
        for (lol i = 1; i < n; i++)
        {
            for (lol j = i - 1; j >= 0; j--)
            {
                if (dp[j].count(stones[i] - stones[j]))
                {
                    dp[i].insert(stones[i] - stones[j] + 1);
                    dp[i].insert(stones[i] - stones[j]);
                    if (stones[i] - stones[j] - 1 >= 0)
                        dp[i].insert(stones[i] - stones[j] - 1);
                }
            }
        }
        return dp[n - 1].size() != 0;
    }
};
// @lc code=end
