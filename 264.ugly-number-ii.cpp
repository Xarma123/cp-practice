/*
 * @lc app=leetcode id=264 lang=cpp

 *
 * [264] Ugly Number II
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol unsigned long long
using namespace std;
class Solution
{
public:
    int nthUglyNumber(int n)
    {
        lol dp[n];
        dp[0] = 1;
        lol x = 2, y = 3, z = 5;
        lol px = 0, py = 0, pz = 0;

        lol j = 1;
        while (j < n)
        {
            if (x * dp[px] <= min(y * dp[py], z * dp[pz]))
            {
                dp[j] = x * dp[px];

                j++;
            }
            else if (y * dp[py] <= min(x * dp[px], z * dp[pz]))
            {
                dp[j] = y * dp[py];

                j++;
            }
            else
            {
                dp[j] = z * dp[pz];

                j++;
            }
            if (dp[j - 1] == y * dp[py])
                py++;
            if (dp[j - 1] == z * dp[pz])
                pz++;
            if (dp[j - 1] == x * dp[px])
                px++;
        }
        return dp[n - 1];
    }
};
// @lc code=end
