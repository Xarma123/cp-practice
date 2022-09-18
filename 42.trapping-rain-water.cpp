/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
#include<bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    int trap(vector<int> &height)
    {
        lol n = height.size();
        lol i = 0;
        lol j = n - 1;
        int left=height[i];
        int right=height[j];
        lol ans=0;
        while (i<j)
        {
            if(left<=right)
            {
                ans+=max(left-height[i],0);
                i++;
                if(i<j)
                left=max(left,height[i]);
            }
            else
            {
                 ans+=max(right-height[j],0);
                j--;
                if(i<j)
                right=max(right,height[j]);
            }
        }
        return ans;
        
    }
};
// @lc code=end
