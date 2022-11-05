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
TreeNode *search(TreeNode *a, ll v)
{
    ll i = upper_bound(a->key.begin(), a->key.end(), v) - a->key.begin();
    if (a->leaf)
    {
        i--;
        if (i >= 0 && a->key[i] == v)
            return a;
        else
            return NULL;
    }
    else
    {
        return search(a->p[i], v);
    }
}
void check(TreeNode *a, ll pv);
void internalmerge(TreeNode *a, TreeNode *b)
{
    TreeNode *c = new TreeNode(m);
    ll pv = b->key[0];

    for (auto e : a->key)
        c->key.push_back(e);

    TreeNode *par = a->parent;
    ll i = lower_bound(par->key.begin(), par->key.end(), pv) - par->key.begin();
    i--;
    c->key.push_back(par->key[i]);
    for (auto e : b->key)
        c->key.push_back(e);
    c->p.assign(c->key.size() + 1, NULL);
    for (ll i = 0; i < a->p.size(); i++)
    {
        c->p[i] = a->p[i];
    }
    for (ll i = 0; i < b->p.size(); i++)
    {
        c->p[i + a->p.size()] = b->p[i];
    }

    c->parent = par;
    c->leaf = a->leaf;
    c->left = a->left;
    c->right = b->right;
    if (a->left != NULL)
    {
        a->left->right = c;
    }
    if (b->right != NULL)
    {
        b->right->left = c;
    }

    par->key.erase(par->key.begin() + i);
    par->p[i] = c;
    i++;
    for (; i < par->p.size() - 1; i++)
        par->p[i] = par->p[i + 1];
    par->p.pop_back();

    delete a;
    delete b;

    check(par, pv);
}
void check(TreeNode *a, ll pv)
{

    if (a->parent == NULL)
    {
        ll c = 0;
        TreeNode *x;
        for (auto e : a->p)
        {
            if (e != NULL)
                c++, x = e;
        }
        if (c == 1)
        {
            root = x;
            root->parent = NULL;
            delete a;
        }
    }
    else if (a->key.size() < ceill(m / 2) - 1)
    {
        if (a->left != NULL &&
            a->left->parent == a->parent &&
            a->left->key.size() >= ceill(m / 2))
        {
            // left sibling
            ll k = lower_bound(a->parent->key.begin(), a->parent->key.end(), pv) - a->parent->key.begin();
            k--;
            a->key.insert(a->key.begin(), a->parent->key[k]);
            a->parent->key[k] = a->left->key.back();
            a->left->key.pop_back();
            a->p.insert(a->p.begin(), a->left->p.back());
            a->left->p.back()->parent = a;
            a->left->p.pop_back();
        }
        else if (a->right != NULL &&
                 a->right->parent == a->parent &&
                 a->right->key.size() >= ceill(m / 2))
        { // right sibling
            ll k = upper_bound(a->parent->key.begin(), a->parent->key.end(), pv) - a->parent->key.begin();
            a->key.push_back(a->parent->key[k]);
            a->parent->key[k] = a->right->key[0];
            a->right->key.erase(a->right->key.begin());
            a->p.push_back(a->right->p[0]);
            a->right->p[0]->parent = a;
            a->right->p.erase(a->right->p.begin());
        }
        else
        {
            // merge with right

            if (a->right != NULL &&
                a->right->parent == a->parent)
            {

                internalmerge(a, a->right);
            }
            else if (a->left != NULL &&
                     a->left->parent == a->parent)
            {
                // merge with left

                internalmerge(a->left, a);
            }
        }
    }
    return;
}
void merge(TreeNode *a, TreeNode *b, ll v, bool l)
{

    TreeNode *c = new TreeNode(m);
    ll pv = b->key[0];
    if (l)
    {
        a->key.erase(lower_bound(a->key.begin(), a->key.end(), v));
    }
    else
    {
        b->key.erase(lower_bound(b->key.begin(), b->key.end(), v));
    }
    for (auto e : a->key)
        c->key.push_back(e);
    for (auto e : b->key)
        c->key.push_back(e);
    c->p.assign(c->key.size() + 1, NULL);

    TreeNode *par = a->parent;
    ll i = lower_bound(par->key.begin(), par->key.end(), pv) - par->key.begin();
    par->key.erase(par->key.begin() + i);
    par->p[i] = c;
    i++;
    for (; i < par->p.size() - 1; i++)
        par->p[i] = par->p[i + 1];
    par->p.pop_back();
    c->parent = par;
    c->leaf = a->leaf;
    c->left = a->left;
    c->right = b->right;
    if (a->left != NULL)
    {
        a->left->right = c;
    }
    if (b->right != NULL)
    {
        b->right->left = c;
    }
    ll mn = c->key[0];

    while (c)
    {
        for (ll i = 0; i < c->key.size(); i++)
        {
            if (c->key[i] == v)
            {
                c->key[i] = mn;
            }
        }
        c = c->parent;
    }

    delete a;
    delete b;

    check(par, pv);
}
void _delete(ll v)
{
    TreeNode *a = search(root, v);
    if (a == NULL)
    {
        cout << "Not Found!" << endl;
        return;
    }

    if (a->key.size() >= ceill(m / 2))
    {
        a->key.erase(lower_bound(a->key.begin(), a->key.end(), v));
        while (a->p.size() > a->key.size() + 1)
            a->p.pop_back();
        ll mn = a->key[0];

        while (a)
        {
            for (ll i = 0; i < a->key.size(); i++)
            {
                if (a->key[i] == v)
                {
                    a->key[i] = mn;
                }
            }
            a = a->parent;
        }
    }
    else
    {

        if (a->left != NULL &&
            a->left->parent == a->parent &&
            a->left->key.size() >= ceill(m / 2))
        {
            // left sibling
            a->key.insert(a->key.begin(), a->left->key.back());
            a->left->key.pop_back();
            (*lower_bound(a->parent->key.begin(), a->parent->key.end(), a->key[1])) = a->key[0];
            while (a->p.size() > a->key.size() + 1)
                a->p.pop_back();
            while (a->p.size() < a->key.size() + 1)
                a->p.push_back(NULL);
            while (a->left->p.size() > a->left->key.size() + 1)
                a->left->p.pop_back();
            while (a->left->p.size() < a->key.size() + 1)
                a->left->p.push_back(NULL);
            _delete(v);
        }
        else if (a->right != NULL &&
                 a->right->parent == a->parent &&
                 a->right->key.size() >= ceill(m / 2))
        {

            a->key.push_back(a->right->key[0]);
            a->right->key.erase(a->right->key.begin());
            (*lower_bound(a->parent->key.begin(), a->parent->key.end(), a->key.back())) = a->right->key[0];
            while (a->p.size() > a->key.size() + 1)
                a->p.pop_back();
            while (a->p.size() < a->key.size() + 1)
                a->p.push_back(NULL);
            while (a->right->p.size() > a->right->key.size() + 1)
                a->right->p.pop_back();
            while (a->right->p.size() < a->key.size() + 1)
                a->right->p.push_back(NULL);
            _delete(v);
        }
        else
        {

            // merge with right

            if (a->right != NULL &&
                a->right->parent == a->parent)
            {

                merge(a, a->right, v, true);
            }
            else if (a->left != NULL &&
                     a->left->parent == a->parent)
            {
                // merge with left

                merge(a->left, a, v, false);
            }
            else
            {
                a->key.erase(lower_bound(a->key.begin(), a->key.end(), v));
            }
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << "Write order of the B+Tree " << endl;
    cin >> m;

    root = new TreeNode(m);
    root->leaf = true;
    cout << "Commands: " << endl;
    cout << "insert x" << endl;
    cout << "delete x" << endl;
    cout << "print" << endl;
    cout << "exit" << endl;
    while (1)
    {
        string s;
        cin >> s;

        if (s == "insert")
        {
            ll x;
            cin >> x;
            insert(x);
        }
        else if (s == "delete")
        {
            ll x;
            cin >> x;
            _delete(x);
        }
        else if (s == "print")
        {
            dfs(root);
        }
        else if (s == "exit")
            break;
    }

    return 0;
}