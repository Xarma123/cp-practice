/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        lol ans = 0;
        bool n = true;
        lol mx = LONG_LONG_MIN;
        lol cans = 0;
        for (lol i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
                n = false;
            mx = max(mx, (long long)nums[i]);
            cans += nums[i];
            ans = max(ans, cans);
            if (cans < 0)
                cans = 0;
        }

        if (n)
            return mx;
        else
        return ans;
    }
};
// @lc code=end
