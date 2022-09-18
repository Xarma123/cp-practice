/*
 * @lc app=leetcode id=474 lang=cpp
 *
 * [474] Ones and Zeroes
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    pair<lol, lol> cal(string a)
    {

        lol z = 0;
        for (lol i = 0; i < a.size(); i++)
        {
            if (a[i] == '0')
                z++;
        }
        return {z, a.size() - z};
    }

    int findMaxForm(vector<string> &strs, int m, int n)
    {
        lol sz = strs.size();
        lol dp[m + 1][n + 1][sz + 1];
        memset(dp, 0, sizeof(dp));
        for (lol i = 0; i <= m; i++)
        {
            for (lol j = 0; j <= n; j++)
            {
                for (lol k = 1; k <= sz; k++)
                {
                    dp[i][j][k] = dp[i][j][k - 1];
                    pair<lol, lol> zo = cal(strs[k - 1]);
                    if (i - zo.first >= 0 && j - zo.second >= 0)
                    {
                        dp[i][j][k] = max(dp[i][j][k], dp[i - zo.first][j - zo.second][k - 1]+1);
                    }
                }
            }
        } 
        return dp[m][n][sz];
    } 

};
// @lc code=end
