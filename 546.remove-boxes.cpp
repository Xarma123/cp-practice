/*
 * @lc app=leetcode id=546 lang=cpp
 *
 * [546] Remove Boxes
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;

class Solution
{
public:
    lol dp[102][102][102];

    lol solve(vector<pair<lol, lol>> &g, lol i, lol j, lol ex)
    {
        if (dp[i][j][ex] != -1)
            return dp[i][j][ex];
        if (i > j)
            return 0;
        lol ans = LONG_LONG_MIN;
        ans = max(ans, ((g[i].second + ex) * (g[i].second + ex) + solve(g, i + 1, j, 0)));
        for (lol k = i + 1; k <= j; k++)
        {
            if (g[i].first == g[k].first)
            {
                ans = max(ans, solve(g, i + 1, k - 1, 0) + solve(g, k, j, g[i].second + ex));
            }
        }
        dp[i][j][ex] = ans;
        return ans;
    }
    int removeBoxes(vector<int> &boxes)
    {
        lol n = boxes.size();
        vector<pair<lol, lol>> g;
        memset(dp, -1, sizeof(dp));
        for (lol i = 0; i < n; i++)
        {
            lol j = i + 1;
            if (j < n)
            {
                while (boxes[i] == boxes[j])
                {
                    j++;
                    if (j == n)
                        break;
                }
            }
            g.push_back({boxes[i], j - i});
            i = j - 1;
        }

        return solve(g, 0, g.size() - 1, 0);
    }
};
// @lc code=end
