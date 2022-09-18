/*
 * @lc app=leetcode id=357 lang=cpp
 *
 * [357] Count Numbers with Unique Digits
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    int countNumbersWithUniqueDigits(int n)
    {   if(n==0)
         return 1;
        lol ans = 0;
        for (lol i = 1; i <= n; i++)
        {
            if (i == 1)
                ans += 10; 
            else
            {
                lol V1=9;
                lol v=9;
                lol c=1;
                while (c<i)
                {
                   V1*=v;
                   v--;
                   c++;
                }
                ans+=V1;
                
            }
        }
        return ans;
    }
};
// @lc code=end
