/*
 * @lc app=leetcode id=375 lang=cpp
 *
 * [375] Guess Number Higher or Lower II
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    int getMoneyAmount(int n)
    {
        lol ans = LONG_LONG_MIN;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            a[i] = i + 1;
        }

        for (lol i = 1; i <= n; i++)
        {
            lol s = 0;
            lol e = n - 1;
            lol c = 0;
            while (s != e - 1)
            {
                lol m = (s + e) / 2;
                if (a[m] < i)
                {
                    c += a[m];
                    s = m;
                }
                else if (a[m] == i)
                    s = m;
                else
                {
                    c += a[m];
                    e = m;
                }
             
            }
            cout << c << endl;
            ans = max(ans, c);
        }
        return ans;
    }
};
// @lc code=end
