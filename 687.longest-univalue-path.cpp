/*
 * @lc app=leetcode id=687 lang=cpp
 *
 * [687] Longest Univalue Path
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
class Solution
{
public:
    map<TreeNode *, lol> mp;
    lol ans = 0;
    void dfs(TreeNode *root)
    {
        if (root == NULL)
            return;
        mp[root] = 0;
        dfs(root->left);
        dfs(root->right);
        if (root->right != NULL && root->left != NULL)
        {
            if (root->right->val == root->left->val && root->val == root->left->val)
            {
                ans = max(ans, mp[root->left] + mp[root->right] + 2);
            }
        }
        if (root->right != NULL && root->val == root->right->val)
        {
            mp[root] = max(mp[root], mp[root->right] + 1);
        }
        if (root->left != NULL && root->val == root->left->val)
        {
            mp[root] = max(mp[root], mp[root->left] + 1);
        }
        ans = max(ans, mp[root]);
    }
    int longestUnivaluePath(TreeNode *root)
    {
        ans = 0;
        mp.clear();
        dfs(root);
        return ans;
    }
};
// @lc code=end
