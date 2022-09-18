/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> dp;
        dp.push_back(0);
        for (lol i = 1; i <= n; i++)
        {
            if (i % 2 == 0)
            {
                dp.push_back(dp[i / 2]);
            }
            else
                dp.push_back(dp[i / 2] + 1);
        }
        return dp;
    }
};
// @lc code=end
