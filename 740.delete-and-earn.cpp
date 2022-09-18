/*
 * @lc app=leetcode id=740 lang=cpp
 *
 * [740] Delete and Earn
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<pair<lol, lol>> dp;
        for (lol i = 0; i < nums.size(); i++)
        {

            int j = i + 1;
            if (j < nums.size())
            {
                while (nums[j] == nums[i])
                {
                    j++;
                    if (j == nums.size())
                        break;
                }
            }

            dp.push_back({nums[i], j - i});
            i = j - 1;
        }

        lol ans = 0;

        int dp2[2][nums.size()];
        bool f = true;
        for (lol i = 0; i <= dp.size(); i++)
        {
            if (i > 0)
            {
                if (i == dp.size())
                {
                    ans += max(dp2[0][i - 1], dp2[1][i - 1]);
                    break;
                }
                if (dp[i].first != dp[i - 1].first + 1)
                {
                    ans += max(dp2[0][i - 1], dp2[1][i - 1]);
                    f = true;
                }
            }
            if (f)
            {
                dp2[0][i] = dp[i].first * 1ll * dp[i].second;
                dp2[1][i] = 0;
            }
            else
            {
                dp2[0][i] = dp[i].first * 1ll * dp[i].second + dp2[1][i - 1];
                dp2[1][i] = max(dp2[0][i - 1], dp2[1][i - 1]);
            }
            f = false;
        }

        return ans;
    }
};
// @lc code=end
