/*
 * @lc app=leetcode id=673 lang=cpp
 *
 * [673] Number of Longest Increasing Subsequence
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
    int findNumberOfLIS(vector<int> &nums)
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
        for (lol i = 0; i < x.size(); i++)
        {
            for (lol j = 0; j < x[i].size(); j++)
            {
                cout << x[i][j] << " ";
            }
            cout << endl;
        }

        vector<lol> pre;
        for (lol i = 1; i <= x[x.size() - 1].size(); i++)
        {
            pre.push_back(i);
        }
      

        for (lol k = x.size() - 2; k >= 0; k--)
        {
            vector<lol> n;
            for (lol i = 0; i < x[k].size(); i++)
            {

                lol j = upper_bound(x[k + 1].begin(), x[k + 1].end(), x[k][i], greater<lol>()) - x[k + 1].end();
               
                n.push_back(pre[j]);
            }
            
            pre.clear();
            for (lol i = 0; i < n.size(); i++)
            {
                pre.push_back(n[i]);
                if (i - 1 >= 0)
                    pre[i] += pre[i - 1];
            } 
            cout<<pre[0]<<" "z
        }
        return pre[pre.size() - 1];
    }
};
// @lc code=end
