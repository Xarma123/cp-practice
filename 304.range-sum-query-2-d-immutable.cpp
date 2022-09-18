/*
 * @lc app=leetcode id=304 lang=cpp
 *
 * [304] Range Sum Query 2D - Immutable
 */

// @lc code=start4
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class NumMatrix
{
public:
    vector<vector<lol>> c;
    NumMatrix(vector<vector<int>> &matrix)
    {
        for (lol i = 0; i < matrix.size(); i++)
        {
            vector<lol> x;
            x.push_back(0);
            for (lol j = 0; j < matrix[0].size(); j++)
            {
                x.push_back(x.back() + matrix[i][j]);
            }
            c.push_back(x);
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        lol ans = 0;
        for (lol i = row1; i <= row2; i++)
        { 
            ans+=c[i][col2+1]-c[i][col1];
        }
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end
