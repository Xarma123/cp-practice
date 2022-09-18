/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    lol bs(vector<deque<lol>> &a, lol x)
    {
        lol s = -1;
        lol e = a.size();
        while (s != e - 1)
        {
            lol m = (s + e) / 2;
            if (m == a.size())
                e = m;
            else if (m == -1)
                s = m;
            else if (a[m][0] >= x)
                e = m;
            else
                s = m;
        }
        return e;
    }
    int lengthOfLIS(vector<int> &nums)
    {
        vector<deque<lol>> x;
        for (lol i = 0; i < nums.size(); i++)
        {
            lol j = bs(x, nums[i]);
            if (j == x.size())
            {
                deque<lol> y;
                y.push_back(nums[i]);
                x.push_back(y);
            }
            else
            {
                x[j].push_front(nums[i]);
            }
        }
        return x.size();
    }
};
// @lc code=end
