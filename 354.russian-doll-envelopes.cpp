/*
 * @lc app=leetcode id=354 lang=cpp
 *
 * [354] Russian Doll Envelopes
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
bool cmp(vector<int> a, vector<int> b)
{
    if (a[0] < b[0])
        return true;
    if (a[0] == b[0])
    {
        return (a[1] > b[1]);
    }
    return false;
}
class Solution
{
public:
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        sort(envelopes.begin(), envelopes.end(), cmp);

        vector<lol> q;
        for (lol i = 0; i < envelopes.size(); i++)
        {
            lol j = lower_bound(q.begin(), q.end(), envelopes[i][1]) - q.begin();
            if (j == q.size())
                q.push_back(envelopes[i][1]);
            else
            {
                q[j] = envelopes[i][1];
            }
        }
        return q.size();
    }
};
// @lc code=end
