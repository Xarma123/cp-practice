/*
 * @lc app=leetcode id=321 lang=cpp
 *
 * [321] Create Maximum Number
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    string v1(deque<lol> n, lol k)
    {

        string ans = "";
        lol K = k;
        while (ans.size() != K)
        {
            lol mx1 = -1;
            for (lol i = 0; i < n.size(); i++)
            {
                if (n.size() - i - 1 < k - 1)
                    continue;
                if (mx1 == -1)
                    mx1 = i;
                if (n[mx1] < n[i])
                    mx1 = i;
            }
            k--;
            ans.push_back(char(n[mx1] + '0'));
            while (mx1--)
                n.pop_front();
            n.pop_front();
        }

        return ans;
    }
    vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k)
    {
        lol n = nums1.size();
        lol m = nums2.size();
        deque<lol> n1;
        deque<lol> n2;
        for (lol i = 0; i < n; i++)
        {
            n1.push_back(nums1[i]);
        }
        for (lol i = 0; i < m; i++)
        {
            n2.push_back(nums2[i]);
        }

        string ans = "";
        for (lol i = 0; i <= k; i++)
        {
            if (i > n || (k - i) > m)
                continue;
            string s1 = v1(n1, i);
            string s2 = v1(n2, k - i);
            string q = "";
            lol j1 = 0, j2 = 0;

            while (j1 < s1.size() && j2 < s2.size())
            {
                if (s1[j1] > s2[j2])
                {
                    q.push_back(s1[j1]);
                    j1++;
                }
                else if (s1[j1] == s2[j2])
                {
                    if (s1.substr(j1 + 1) >= s2.substr(j2 + 1))
                    {
                        q.push_back(s1[j1]);
                        j1++;
                    }
                    else
                    {
                        q.push_back(s2[j2]);
                        j2++;
                    }
                }
                else
                {
                    q.push_back(s2[j2]);
                    j2++;
                }
            }

            while (j1 < s1.size())
            {
                q.push_back(s1[j1]);
                j1++;
            }
            while (j2 < s2.size())
            {
                q.push_back(s2[j2]);
                j2++;
            }

            if (ans == "")
                ans = q;
            else
                ans = max(ans, q);
        }

        vector<int> q;
        while (k--)
        {
            q.push_back(ans.back() - '0');
            ans.pop_back();
        }
        reverse(q.begin(), q.end());
        return q;
    }
};
// @lc code=end
