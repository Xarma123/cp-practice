/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        lol n = nums1.size();
        lol m = nums2.size();
        if (n == 0 && m == 0)
        {
            return 0;
        }
        if (n == 0)
        {
            if (m % 2 == 0)
            {
                return (nums2[m / 2] + nums2[m / 2 - 1]) / (long double)2;
            }
            else
            {
                return nums2[m / 2];
            }
        }
        if (m == 0)
        {
            if (n % 2 == 0)
            {
                return (nums1[n / 2] + nums1[n / 2 - 1]) / (long double)2;
            }
            else
            {
                return nums1[n / 2];
            }
        }
        lol s = -1;
        lol e = n;
        while (s != e - 1)
        {

            lol md = (s + e) / 2;

            if (md == n)
                e = n;
            else if (md == -1)
                s = md;
            else
            {
                lol ex = md + 1 + (upper_bound(nums2.begin(), nums2.end(), nums1[md]) - nums2.begin());

                if (ex >= (n + m) / 2)
                {
                    e = md;
                }
                else
                    s = md;
            }
        }

        lol i, j;
        if (e == n)
        {
            i = n - 1;
            j = (n + m) / 2 - n - 1;
        }
        else
        {
            j = lower_bound(nums2.begin(), nums2.end(), nums1[e]) - nums2.begin();

            lol ex2;

            ex2 = e + j;

            j--;
            i = e - 1;
            if (ex2 > (n + m) / 2)
            {
                while (i >= 0 && j >= 0 && ex2 - ((n + m) / 2) > 0)
                {
                    if (nums1[i] >= nums2[j])
                    {
                        i--;
                    }
                    else
                        j--;
                    ex2--;
                }
                while (i >= 0 && ex2 - ((n + m) / 2) > 0)
                {

                    i--;

                    ex2--;
                }
                while (j >= 0 && ex2 - ((n + m) / 2) > 0)
                {

                    j--;

                    ex2--;
                }
            }
            else
            {

                lol d = (n + m) / 2 - ex2;

                if (d)
                {
                    i++;
                    d--;
                }

                while (d)
                {
                    j++;
                    d--;
                }
            }
        }
        if ((n + m) % 2 == 0)
        {
            lol a = LONG_LONG_MIN;
            lol b = LONG_LONG_MAX;
            if (i >= 0 && i < n)
            {
                a = max(a, (long long)nums1[i]);
            }
            if (j >= 0 && j < m)
            {
                a = max(a, (long long)nums2[j]);
            }
            i++;
            j++;
            if (i >= 0 && i < n)
            {
                b = min(b, (long long)nums1[i]);
            }
            if (j >= 0 && j < m)
            {
                b = min(b, (long long)nums2[j]);
            }
            return (a + b) / (long double)2;
        }
        else
        {
            lol b = LONG_LONG_MAX;
            i++;
            j++;
            if (i >= 0 && i < n)
            {
                b = min(b, (long long)nums1[i]);
            }
            if (j >= 0 && j < m)
            {
                b = min(b, (long long)nums2[j]);
            }
            return b;
        }
    }
};
// @lc code=end
