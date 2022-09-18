/*
 * @lc app=leetcode id=698 lang=cpp
 *
 * [698] Partition to K Equal Sum Subsets
 */

// @lc code=start
#include <bits/stdc++.h>
#define lol long long
using namespace std;
class Solution
{
public:
    int q;
    bool check(vector<int> &a, int sum, int k, lol i)
    {
        if (k == 0)
            return true;
        if (sum == 0)
        {

            return check(a, q, k - 1, 0);
        }
        if (i == a.size())
            return false;

        if (a[i] > 0 && a[i] <= sum)
        {
            lol c = a[i];
            a[i] = 0;
            if (check(a, sum - c, k, i + 1))
                return true;

            a[i] = c;
            lol j = i + 1;
            if (j < a.size())
            {
                while (a[j] == a[i])
                {
                    j++;
                    if (j == a.size())
                        break;
                }
            }
            i = j - 1;
        }

        return check(a, sum, k, i + 1);
    }
    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        lol sum = 0;
        for (lol i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        if (sum % k != 0)
            return false;
        sum /= k;
        q = sum;
        for (lol i = 0; i < nums.size(); i++)
        {
            if (nums[i] > sum)
                return false;
        }
        sort(nums.rbegin(), nums.rend());

        return check(nums, sum, k, 0);
    }
};
// @lc code=end
