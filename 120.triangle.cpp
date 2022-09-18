/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        for (lol i = triangle.size() - 1; i >= 0; i--)
        {
            for (lol j = 0; j < triangle[i].size(); j++)
            {
                if (i + 1 < triangle.size())
                {
                    triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
                }
            }
        }
        return triangle[0][0];
    }
};
// @lc code=end
