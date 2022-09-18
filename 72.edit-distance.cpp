/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        lol dp[word1.size() + 1][word2.size() + 1];
        for (lol i = 0; i <= word2.size(); i++)
        {
            dp[0][i] = i;
        }
        for (lol i = 0; i <= word1.size(); i++)
        {
            dp[i][0] = i;
        }
        for (lol i = 1; i <= word1.size(); i++)
        {
            for (lol j = 1; j <= word2.size(); j++)
            {
                dp[i][j] = LONG_LONG_MAX;
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
            }
        }
        return dp[word1.size()][word2.size()];
    }
};
// @lc code=end
