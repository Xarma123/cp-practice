#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};
Node *insert(Node *root, int key)
{
    if (root == NULL)
        return new Node(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}
bool checkBST(Node *node, int mn, int mx)
{
    if (node == NULL)
        return true;
    cout << node->data << " " << mn << " " << mx << endl;
    if (node->data < mn || node->data > mx)
        return false;
    return checkBST(node->left, mn, node->data) && checkBST(node->right, node->data, mx);
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int keys[] = {15, 10, 20, 8, 12, 16, 25};
    Node *root = NULL;
    for (int key : keys)
    {
        root = insert(root, key);
    }
 
    if (checkBST(root, INT_MIN, INT_MAX))
    {
        cout << "Valid Bst" << endl;
    }
    else
        cout << "Not Valid" << endl;

    return 0;
}