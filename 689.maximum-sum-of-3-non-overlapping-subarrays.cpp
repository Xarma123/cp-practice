/*
 * @lc app=leetcode id=689 lang=cpp
 *
 * [689] Maximum Sum of 3 Non-Overlapping Subarrays
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k)
    {
        pair<lol, vector<int>> dp[3][nums.size()];

        for (lol i = 0; i < 3; i++)
        {
            for (lol j = 0; j < nums.size(); j++)
            {
                vector<int> x;
                dp[i][j] = {0, x};
            }
        }

        lol s = 0;
        for (lol i = 0; i < nums.size(); i++)
        {
            if (i < k)
            {
                s += nums[i];

                if (i == k - 1)
                {
                    dp[0][i].first = s;
                    dp[0][i].second.push_back(0);
                }
            }
            else
            {
                s += nums[i];
                s -= nums[i - k];
                if (s <= dp[0][i - 1].first)
                {
                    dp[0][i] = dp[0][i - 1];
                }
                else
                {
                    dp[0][i].first = s;
                    dp[0][i].second.push_back(i - k + 1);
                }
            }
        }
        s = 0;
        for (lol i = 0; i < nums.size(); i++)
        {
            if (i < 2 * k)
            {
                s += nums[i];
                if (i == 2 * k - 1)
                {
                    dp[1][i].first = s;
                    dp[1][i].second.push_back(0);
                    dp[1][i].second.push_back(k);
                }
                s -= dp[0][k - 1].first;
            }
            else
            {
                s += nums[i];
                s -= nums[i - k];
                if (dp[1][i - 1].first >= s + dp[0][i - k].first)
                {
                    dp[1][i] = dp[1][i - 1];
                }
                else
                {
                    dp[1][i] = dp[0][i - k];
                    dp[1][i].first += s;
                    dp[1][i].second.push_back(i - k + 1);
                }
            }
        }
        s = 0;
        for (lol i = 0; i < nums.size(); i++)
        {
            if (i < 3 * k)
            {
                s += nums[i];
                if (i == 3 * k - 1)
                {
                    dp[2][i].first = s;
                    dp[2][i].second.push_back(0);
                    dp[2][i].second.push_back(k);
                    dp[2][i].second.push_back(2 * k);
                }
                s -= dp[1][2*k - 1].first;
            }
            else
            {
                s += nums[i];
                s -= nums[i - k];
                if (dp[2][i - 1].first >= s + dp[1][i - k].first)
                {
                    dp[2][i] = dp[2][i - 1];
                }
                else
                {
                    dp[2][i] = dp[1][i - k];
                    dp[2][i].first += s;
                    dp[2][i].second.push_back(i - k + 1);
                }
            }
        }

        return dp[2][nums.size() - 1].second;
    }
};
// @lc code=end
