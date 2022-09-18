/*
 * @lc app=leetcode id=464 lang=cpp
 *
 * [464] Can I Win
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal)
    {
        bool dp[desiredTotal + 1][maxChoosableInteger + 1];

        for (lol i = 0; i <= maxChoosableInteger; i++)
        {
            dp[0][i] = true;
        }
        for (lol i = 1; i <= desiredTotal; i++)
        {
            dp[i][0] = false;
        }
        for (lol i = 1; i <= desiredTotal; i++)
        {
            for (lol j = 1; j <= maxChoosableInteger; j++)
            {
                dp[i][j] = false;
                if (i - j > 0)
                {
                    dp[i][j] |= (!dp[i - j][j - 1]);
                }
                else
                {
                    dp[i][j] = true;
                }
            }
        }

        return dp[desiredTotal][maxChoosableInteger];
    }
};
// @lc code=end
