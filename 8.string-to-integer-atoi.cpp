/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    int myAtoi(string s)
    {
        if (s.size() == 0)
            return 0;
        char l = '\n';
        lol i = 0;
        while (s[i] == ' ')
        {
            i++;
            if (i == s.size())
                break;
        }
        if (i == s.size())
            return 0;
        bool n = false;
        if (!(s[i] >= '0' && s[i] <= '9'))
        {
            if (s[i] == '+')
                n = false;
            else if (s[i] == '-')
                n = true;
            else
                return 0;
            i++;
        }

        lol ans = 0;

        if (i < s.size())
        {
            while ((s[i] >= '0' && s[i] <= '9'))
            {

                ans = ans * 1ll * 10 + (s[i] - '0');
                if (n && ans >= 2147483648)
                    return 2147483648;
                if ((!n) && ans >= 2147483647)
                    return 2147483647;
                i++;
                if (i == s.size())
                    break;
            }
        }
        if (n)
            ans = -ans;
        if (ans >= 2147483647)
            return 2147483647;
        else if (ans <= -2147483648)
            return -2147483648;
        return ans;
    }
};
// @lc code=end
