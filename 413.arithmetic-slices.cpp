/*
 * @lc app=leetcode id=413 lang=cpp
 *
 * [413] Arithmetic Slices
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        lol n = nums.size();
        bool arth[n][n];
        lol ans = 0;
        for (lol k = 0; k < n; k++)
        {
            for (lol i = 0, j = k; i < n && j < n; i++, j++)
            {
                arth[i][j] = false;
                if (j - i <= 1)
                {
                    arth[i][j] = true;
                }
                else
                {

                    if (arth[i][j - 1])
                    {
                        lol d = nums[i + 1] - nums[i];
                        if (nums[j - 1] + d == nums[j])
                        {
                            arth[i][j] = true;
                            ans++;
                        }
                    }
                }
            }
        } 
        return ans;
    }
};
// @lc code=end
