/*
 * @lc app=leetcode id=368 lang=cpp
 *
 * [368] Largest Divisible Subset
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        lol n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> ar[n];
        for (lol i = 0; i < n; i++)
        {
            ar[i].push_back(nums[i]);
        }
        lol mx = 0;
        for (lol i = n - 1; i >= 0; i--)
        {
            lol k = -1;
            for (lol j = i + 1; j < n; j++)
            {
                if (ar[j][0] % ar[i][0] == 0)
                {
                    if (k == -1)
                        k = j;
                    else if (ar[k].size() < ar[j].size())
                        k = j;
                }
            }
            if (k != -1)
            {
                for (lol j = 0; j < ar[k].size(); j++)
                {
                    ar[i].push_back(ar[k][j]);
                }
            }
            if (ar[i].size() > ar[mx].size())
                mx = i;
        } 
        return ar[mx];
    }
};
// @lc code=end
