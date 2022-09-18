/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <bits/stdc++.h>
#define lol long long
using namespace std;
// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };
class Solution
{
public:
    vector<TreeNode *> ans(lol st, lol end)
    {
        if (st > end)
        {
            vector<TreeNode *> x;
            x.push_back(NULL);
            return x;
        }
        vector<TreeNode *> q;
        for (lol i = st; i <= end; i++)
        {
            vector<TreeNode *> x = ans(st, i - 1);
            vector<TreeNode *> y = ans(i + 1, end);
            for (lol j = 0; j < x.size(); j++)
            {
                for (lol k = 0; k < y.size(); k++)
                {
                    TreeNode *s = new TreeNode(i);
                    s->left = x[j];
                    s->right = y[k];
                    q.push_back(s);
                }
            }
        }
        return q;
    }
    vector<TreeNode *> generateTrees(int n)
    {
        return ans(1, n);
    }
};
// @lc code=end
