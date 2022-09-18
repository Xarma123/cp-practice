/*
 * @lc app=leetcode id=639 lang=cpp
 *
 * [639] Decode Ways II
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    lol m = 1e9 + 7;
    int numDecodings(string s)
    {
        lol n = s.size();
        lol dp[n + 1];
        memset(dp, 0, sizeof(dp));
        dp[n] = 1;
        for (lol i = n - 1; i >= 0; i--)
        {
            if (s[i] == '0')
            {
                dp[i] = 0;
            }
            else if (s[i] == '*')
            {
                dp[i] += (9 * dp[i + 1]) % m;
                dp[i] %= m;
            }
            else
            {
                dp[i] += (dp[i + 1]) % m;
                dp[i] %= m;
            }
            if (i + 1 < n)
            {
                if (s.substr(i, 2) == "**")
                {
                    dp[i] += (15 * dp[i + 2]) % m;
                    dp[i] %= m;
                }
                else if (s[i] == '*')
                {
                    if (s[i + 1] <= '6')
                    {
                        dp[i] += (2 * dp[i + 2]) % m;
                        dp[i] %= m;
                    }
                    else
                        dp[i] += (dp[i + 2]) % m;
                    dp[i] %= m;
                }
                else if (s[i] == '1')
                {
                    if (s[i + 1] == '*')
                    {
                        dp[i] += (9 * dp[i + 2]) % m;
                        dp[i] %= m;
                    }
                    else
                        dp[i] += (dp[i + 2]) % m;
                    dp[i] %= m;
                }
                else if (s[i] == '2')
                {
                    if (s[i + 1] == '*')
                    {
                        dp[i] += (6 * dp[i + 2]) % m;
                        dp[i] %= m;
                    }
                    else if (s[i + 1] <= '6')
                        dp[i] += (dp[i + 2]) % m;
                    dp[i] %= m;
                }
            }
        }
        return dp[0];
    }
};
// @lc code=end
