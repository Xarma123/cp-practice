/*
 * @lc app=leetcode id=600 lang=cpp
 *
 * [600] Non-negative Integers without Consecutive Ones
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    lol dp[2][50];
    lol solve(string s)
    {
        if (s.size() == 0)
            return 1;
        lol n = s.size();
        n--;
        s.pop_back();
        if (s.size())
        {
            while (s.back() != '1')
            {
                s.pop_back();
                if (s.size() == 0)
                    break;
            }
        }
        lol ans = 0;
        if (n == 0)
        {
            ans++;
        }
        else
        {
            ans += dp[0][n];
            ans += dp[1][n];
        }
        if (s.size() == 0)
            ans++;
        else
        {

            if (s.size() == n)
            {
                ans += dp[0][s.size()];
            }
            else
                ans += solve(s);
        }
        return ans;
    }
    int findIntegers(int n)
    {
        dp[0][1] = 1;
        dp[1][1] = 1;
        for (lol i = 2; i < 50; i++)
        {
            dp[0][i] += dp[0][i - 1];
            dp[0][i] += dp[1][i - 1];
            dp[1][i] += dp[0][i - 1];
        }

        string s = "";
        while (n > 0)
        {
            if (n % 2 == 0)
                s.push_back('0');
            else
                s.push_back('1');
            n /= 2;
        }
        cout << s;

        return solve(s);
    }
};
// @lc code=end
