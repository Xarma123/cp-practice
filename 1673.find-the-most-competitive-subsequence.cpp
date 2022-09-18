/*
 * @lc app=leetcode id=1673 lang=cpp
 *
 * [1673] Find the Most Competitive Subsequence
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    vector<int> mostCompetitive(vector<int> &nums, int k)
    {
        lol n = nums.size();
        vector<int> ans;
        priority_queue<pair<lol, lol>,vector<pair<lol,lol>>,greater<pair<lol,lol>>> x;
        for (lol i = 0; i < n - k + 1; i++)
        {
            x.push({nums[i], i});
        }
        lol i = n - k + 1;
        while (k--)
        {
            ans.push_back(x.top().first);
            lol j = x.top().second;
            while (x.top().second <= j)
            {
                x.pop();
                if (x.size() == 0)
                    break;
            }
            if (i < n)
                x.push({nums[i], i});
            i++;
        }

        return ans;
    }
};
// @lc code=end
