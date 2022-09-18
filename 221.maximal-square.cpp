/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    lol n, m;
    lol hist(lol a[])
    {
        lol ans = LONG_LONG_MIN;
        stack<pair<lol, lol>> x;
        lol l[n];
        lol r[n];
        l[0] = -1;
        x.push({a[0], 0});
        for (lol i = 1; i < n; i++)
        {
            if (x.size())
            {
                while (x.top().first >= a[i])
                {
                    r[x.top().second] = i;
                    x.pop();

                    if (x.size() == 0)
                        break;
                }
            }
            if (x.size())
            {
                l[i] = x.top().second;
            }
            else
                l[i] = -1;
            x.push({a[i], i});
        }
        while (x.size())
        {
            r[x.top().second] = n;
            x.pop();
        }
        for (lol i = 0; i < n; i++)
        {

            ans = max(ans, (long long)powl(min(r[i] - l[i] - 1, a[i]), 2));
        }
        return ans;
    }
    int maximalSquare(vector<vector<char>> &matrix)
    {
        m = matrix.size();
        n = matrix[0].size();
        lol a[n];
        memset(a, 0, sizeof(a));
        lol ans = LONG_LONG_MIN;
        for (lol i = 0; i < m; i++)
        {
            for (lol j = 0; j < n; j++)
            {
                if (matrix[i][j] == '0')
                    a[j] = 0;
                else
                    a[j]++;
            }

            ans = max(ans, hist(a));
        }
        if (ans != LONG_LONG_MIN)
            return ans;
        else
            return 0;
    }
};
// @lc code=end
