/*
 * @lc app=leetcode id=552 lang=cpp
 *
 * [552] Student Attendance Record II
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    lol m = 1e9 + 7;
    int checkRecord(int n)
    {
        lol dp[6][n + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][1] = 1;
        dp[1][1] = 1;
        dp[3][1] = 1;
        for (lol j = 0; j <= n; j++)
        {
            for (lol i = 0; i < 6; i++)
            {
                if (j == 0)
                {
                }
                else
                {
                    if (i == 0)
                    {
                        dp[i][j] += dp[0][j - 1];
                        dp[i][j] %= m;
                        dp[i][j] += dp[1][j - 1];
                        dp[i][j] %= m;
                        dp[i][j] += dp[2][j - 1];
                        dp[i][j] %= m;
                    }
                    else if (i == 1)
                    {
                        dp[i][j] += dp[0][j - 1];
                        dp[i][j] %= m;
                    }
                    else if (i == 2)
                    {
                        dp[i][j] += dp[1][j - 1];
                        dp[i][j] %= m;
                    }
                    else if (i == 3)
                    {
                        dp[i][j] += dp[0][j - 1];
                        dp[i][j] %= m;
                        dp[i][j] += dp[1][j - 1];
                        dp[i][j] %= m;
                        dp[i][j] += dp[2][j - 1];
                        dp[i][j] %= m;
                        dp[i][j] += dp[3][j - 1];
                        dp[i][j] %= m;
                        dp[i][j] += dp[4][j - 1];
                        dp[i][j] %= m;
                        dp[i][j] += dp[5][j - 1];
                        dp[i][j] %= m;
                    }
                    else if (i == 4)
                    {
                        dp[i][j] += dp[3][j - 1];
                        dp[i][j] %= m;
                    }
                    else if (i == 5)
                    {
                        dp[i][j] += dp[4][j - 1];
                        dp[i][j] %= m;
                    }
                }
            }
        }
        lol ans = 0;
        for (lol i = 0; i < 6; i++)
        {
            ans += dp[i][n];
            ans %= m;
        }
        return ans;
    }
};
// @lc code=end
