/*
 * @lc app=leetcode id=523 lang=cpp
 *
 * [523] Continuous Subarray Sum
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        
        lol n = nums.size();
        lol c[n + 1];
        c[0] = 0;
        for (lol i = 0; i < n; i++)
        {
            c[i + 1] = c[i] + nums[i];
        }
        for (lol i = 1; i <= n; i++)
        {
            c[i] %= k;
        }
        unordered_set<lol> mp;
        for (lol i = 1; i <= n; i++)
        {
            if (mp.count(c[i]))
                return true;
            mp.insert(c[i - 1]);
        }
        return false;
    }
};
// @lc code=end
