/*
 * @lc app=leetcode id=363 lang=cpp
 *
 * [363] Max Sum of Rectangle No Larger Than K
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    int maxSumSubmatrix(vector<vector<int>> &matrix, int K)
    {
        lol n = matrix.size();
        lol m = matrix[0].size();
        lol c[n + 1][m];
        for (lol i = 0; i <= n; i++)
        {
            for (lol j = 0; j < m; j++)
            {
                if (i == 0)
                    c[i][j] = 0;
                else
                {
                    c[i][j] = c[i - 1][j] + matrix[i - 1][j];
                }
            }
        } 
        lol ans=LONG_LONG_MIN;
        for (lol i = 1; i <= n; i++)
        {
            for (lol j = i; j <= n; j++)
            {
                set<lol> x;
                x.insert(0);
                lol s = 0;
                for (lol k = 0; k < m; k++)
                {
                    s += c[j][k] - c[i - 1][k];
                    auto q = lower_bound(x.begin(), x.end(), s - K);
                    if (q != x.end())
                    { 
                        ans=max(ans,s-(*q));
                    }
                    x.insert(s);
                }
            }
        } 
        return ans;
    }
};
// @lc code=end
