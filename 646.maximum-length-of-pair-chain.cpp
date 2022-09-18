/*
 * @lc app=leetcode id=646 lang=cpp
 *
 * [646] Maximum Length of Pair Chain
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    int findLongestChain(vector<vector<int>> &pairs)
    {
        sort(pairs.begin(), pairs.end());

        lol dp[pairs.size()];
        lol ans = 1;
        dp[0] = 1;
        for (lol i = 1; i < pairs.size(); i++)
        {
            dp[i] = 1;
            lol v = 0;
            for (lol j = i - 1; j >= 0; j--)
            {
                if (pairs[j][1] < pairs[i][0])
                {
                    v = max(v, dp[j]);
                }
            }
            dp[i] += v;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
// @lc code=end
