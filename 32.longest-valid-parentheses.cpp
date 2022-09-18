/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        lol ans = LONG_LONG_MIN;
        stack<pair<char, lol>> x;
        for (lol i = 0; i < s.size(); i++)
        {
            if (s[i] == ')')
            {
                if (x.size())
                {
                    if (x.top().first == '(')
                    {
                        x.pop();
                    }
                    else
                        x.push({s[i], i});
                }
                else
                    x.push({s[i], i});
            }
            else
            {

                x.push({s[i], i});
            }
            if (x.size() == 0)
                ans = max(ans, i + 1);
            else
                ans = max(ans, i - x.top().second);
        }
        return ans;
    }
};
// @lc code=end
