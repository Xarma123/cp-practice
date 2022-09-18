/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] Zigzag Conversion
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    string convert(string s, int numRows)
    {   if(s.size()<=numRows||numRows==1)
         return s; 
         
        string ans = "";
        for (lol i = 0; i < numRows&&i<s.size(); i++)
        {
            if (i == 0 || i == numRows - 1)
            {
                for (lol j = i; j < s.size(); j += 2 * (numRows)-2)
                {
                    ans.push_back(s[j]);
                } 
             
            }
            else
            {
                lol tggle = 1;
                for (lol j = i; j < s.size();)
                {
                    ans.push_back(s[j]);
                    if (tggle)
                    {
                        j += 2 * numRows - 2 * i - 2;
                        tggle = 0;
                    }
                    else
                    {
                        j += 2 * i;
                        tggle = 1;
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end
