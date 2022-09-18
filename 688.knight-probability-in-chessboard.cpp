/*
 * @lc app=leetcode id=688 lang=cpp
 *
 * [688] Knight Probability in Chessboard
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol unsigned long long
using namespace std;
class Solution
{
public:
    map<pair<lol, pair<lol, lol>>, long double> mp;
    long double solve(lol x, lol y, lol k, lol n)
    {

        if (mp.count({x, {y, k}}))
            return mp[{x, {y, k}}];

        if (x < 0 || x >= n || y < 0 || y >= n)
        {

            return 0;
        }
        if (k == 0)
        {

            return 1;
        }
        long double ans = 0;
        ans += solve(x - 2, y - 1, k - 1, n);
        ans += solve(x - 1, y - 2, k - 1, n);
        ans += solve(x + 1, y - 2, k - 1, n);
        ans += solve(x + 2, y - 1, k - 1, n);
        ans += solve(x - 2, y + 1, k - 1, n);
        ans += solve(x - 1, y + 2, k - 1, n);
        ans += solve(x + 1, y + 2, k - 1, n);
        ans += solve(x + 2, y + 1, k - 1, n);
        ans = ans / (long double)8;
        mp[{x, {y, k}}] = ans;
        return ans;
    }
    double knightProbability(int n, int k, int row, int column)
    {
        return solve(row, column, k, n);
    }
};
// @lc code=end
