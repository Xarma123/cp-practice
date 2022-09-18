/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        lol n = height.size();
        lol i = 0, j = n - 1;
        lol ans = 0;
        while (i < j)
        { 
            ans=max(ans,(j-i)*1ll*(min(height[i],height[j])));
            if(height[i]<=height[j])
            i++;
            else
            j--;
        }
        return ans;
    }
};
// @lc code=end
