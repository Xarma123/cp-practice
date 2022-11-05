#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll m;
class TreeNode
{
public:
    bool leaf;
    TreeNode *parent;
    TreeNode *left;
    TreeNode *right;
    vector<ll> key;
    vector<TreeNode *> p;
    TreeNode(ll m)
    {
        parent = NULL;
        leaf = false;
        left = NULL;
        right = NULL;
    }
    void print()
    {
        for (auto e : key)
            cout << e << " ";
        cout << endl;
    }
};
TreeNode *root;
void insert(TreeNode *a, ll v, bool in, TreeNode *lf, TreeNode *rf);

void split(TreeNode *a)
{

    ll mid = a->key.size() / 2;
    TreeNode *b = new TreeNode(m);
    b->leaf = a->leaf;
    b->parent = a->parent;
    for (ll i = mid + 1; i < a->key.size(); i++)
    {
        b->key.push_back(a->key[i]);
    }
    if (b->leaf)
    {
        b->key.push_back(a->key[mid]);
    }

    sort(b->key.begin(), b->key.end());

    ll midval = a->key[mid];
    while (a->key.size() != mid)
    {
        a->key.pop_back();
    }

    if (b->leaf)
    {

        b->p.push_back(NULL);
        b->p.push_back(a->p[mid + 1]);
        for (ll i = mid + 2; i < a->p.size(); i++)
        {
            b->p.push_back(a->p[i]);
        }
    }
    else
    {

        for (ll i = mid + 1; i < a->p.size(); i++)
        {
            b->p.push_back(a->p[i]);
        }
    }

    while (a->p.size() > mid + 1)
    {
        a->p.pop_back();
    }

    // neighbours
    b->right = a->right;
    a->right = b;
    b->left = a;

    if (a->parent == NULL)
    {
        a->parent = new TreeNode(m);
        b->parent = a->parent;
        root = a->parent;
    }
    for (auto e : b->p)
    {
        if (e != NULL)
        {
            e->parent = b;
        }
    }

    insert((a->parent), midval, true, a, b);
}

void insert(TreeNode *a, ll v, bool in, TreeNode *lf, TreeNode *rf)
{

    if (a->leaf || in)
    {

        ll i = upper_bound(a->key.begin(), a->key.end(), v) - a->key.begin();
        a->p.insert(a->p.begin() + i, lf);
        if (i + 1 < a->p.size())
            a->p[i + 1] = rf;
        else
            a->p.push_back(rf);

        a->key.push_back(v);

        sort(a->key.begin(), a->key.end());

        if (a->key.size() >= m)
        {
            split(a);
        }
    }
    else
    {
        ll i = upper_bound(a->key.begin(), a->key.end(), v) - a->key.begin();

        insert((a->p[i]), v, false, lf, rf);
    }
}

void insert(ll v)
{
    insert(root, v, false, nullptr, nullptr);
}
void dfs(TreeNode *a)
{
    a->print();
    for (auto e : a->p)
    {
        if (e != NULL)
        {
            dfs(e);
        }
    }
}