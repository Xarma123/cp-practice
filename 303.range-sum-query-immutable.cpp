/*
 * @lc app=leetcode id=303 lang=cpp
 *
 * [303] Range Sum Query - Immutable
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class NumArray
{
public:
    vector<lol> a;
    vector<lol> c;
    NumArray(vector<int> &nums)
    {
        c.push_back(0);
        for (lol i = 0; i < nums.size(); i++)
        {
            a.push_back(nums[i]);
        }
        for (lol i = 0; i < a.size(); i++)
        {
            c.push_back(c.back() + a[i]);
        } 

    }
    int sumRange(int left, int right)
    {   if(left>=0&&right+1<c.size())
        return c[right+1]-c[left]; 
        else 
        return 0;
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end
