/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{

public:
    int reverse(int x)
    {
        lol y = x;
        string s = to_string(y);
        lol i = 0, j = s.size() - 1;
        while (i < j)
        {
            swap(s[i], s[j]);
            i++;
            j--;
        }

        y = stoll(s);
        if (x < 0)
            y = -y;
        if (y < -2147483648 || y >= 2147483648)
            return 0;
        return y;
    }
};
// @lc code=end
