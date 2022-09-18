/*
 * @lc app=leetcode id=446 lang=cpp
 *
 * [446] Arithmetic Slices II - Subsequence
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
#define lol1 unsigned long long
using namespace std;
class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        lol n = nums.size();
        lol1 ans = 0;
        map<lol1, lol1> dp[n];
        for (lol i = 1; i < n; i++)
        {
            for (lol j = i - 1; j >= 0; j--)
            {
                dp[i][(long long)((long long)nums[i] - (long long)nums[j])]++;
            }
        }
        for (lol i = 0; i < n; i++)
        {
            for (lol j = i - 1; j >= 0; j--)
            {
                ans += dp[j][(long long)((long long)nums[i] - (long long)nums[j])];
                dp[i][(long long)((long long)nums[i] - (long long)nums[j])] += dp[j][(long long)((long long)nums[i] - (long long)nums[j])];
            }
        }
        return ans;
    }
};
// @lc code=end
