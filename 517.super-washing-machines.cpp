/*
 * @lc app=leetcode id=517 lang=cpp
 *
 * [517] Super Washing Machines
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    int findMinMoves(vector<int> &machines)
    {
        lol s = 0, n = machines.size();
        for (lol i = 0; i < n; i++)
        {
            s += machines[i];
        }
        if (s % n != 0)
            return -1;
        s /= n;
        lol ans = LONG_LONG_MIN;
        for (lol i = 0; i < n; i++)
        {
            machines[i] -= s;
        }
        lol moves[n];
        memset(moves, 0, sizeof(moves));
        for (lol i = 0; i < n - 1; i++)
        {
          
            machines[i + 1] += machines[i];
            if (machines[i] > 0)
            {
                moves[i] += machines[i];
            }
            else
                moves[i + 1] += -machines[i];
            ans = max(ans, moves[i]);
        }
        ans = max(ans, moves[n-1]+(machines[n-1]>0?(long long)machines[n - 1]:0));

        return ans;
    }
};
// @lc code=end
