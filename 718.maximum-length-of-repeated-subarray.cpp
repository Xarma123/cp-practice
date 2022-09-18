/*
 * @lc app=leetcode id=718 lang=cpp
 *
 * [718] Maximum Length of Repeated Subarray
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        int dp[nums1.size()][nums2.size()];
        int ans = LONG_LONG_MIN;
        for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = 0; j < nums2.size(); j++)
            {
                dp[i][j] = 0; 
                if(nums1[i]==nums2[j])
                {
                    dp[i][j]++;
                    if(i-1>=0&&j-1>=0)
                    dp[i][j]+=dp[i-1][j-1];
                } 
                ans=max(ans,dp[i][j]);
            }
        } 
        return ans;
    }
};
// @lc code=end
