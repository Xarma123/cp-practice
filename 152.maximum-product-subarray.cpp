/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        lol ans = nums[0];
        lol c = nums[0];
        lol cn = 0;
        if (c < 0)
            cn = c;
        if (c == 0)
            c = 1;

        for (lol i = 1; i < nums.size(); i++)
        {
            c *= nums[i];
            if (c > 0)
            {
                ans = max(ans, c);
            }
            else if (c < 0)
            {
                if (cn == 0)
                {
                    ans = max(ans, c);
                    cn = c;
                }
                else
                    ans = max(ans, c / cn);
            }
            else
            {
                ans = max(ans, c);
                c = 1;
                cn = 0;
            }
        }
        return ans;
    }
};
// @lc code=end
