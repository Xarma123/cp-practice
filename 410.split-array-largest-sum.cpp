/*
 * @lc app=leetcode id=410 lang=cpp
 *
 * [410] Split Array Largest Sum
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    bool check(vector<int> nums, int m, int up)
    {
        if (up == -1)
            return false;
        lol s = 0, c = 1;
        for (lol i = 0; i < nums.size(); i++)
        {

            if (nums[i] > up)
                return false;
            if (s + nums[i] <= up)
            {
                s += nums[i];
            }
            else
            {
                c++;
                i--;
                s = 0;
            }
        }
        return c <= m;
    }
    int splitArray(vector<int> &nums, int m)
    {
        lol n = nums.size();
        lol e = 0;
        for (lol i = 0; i < n; i++)
        {
            e += nums[i];
        }
        e++;

        lol s = -1;
        while (s != e - 1)
        {
            lol md = (s + e) / 2;

            if (check(nums, m, md))
                e = md;
            else
                s = md;
        }
        return e;
    }
};
// @lc code=end
