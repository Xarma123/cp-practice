#include <bits/stdc++.h>
#define lol long long
using namespace std;
class segTree
{
public:
    vector<pair<lol, lol>> tree;
    lol n = 1;
    segTree(lol c)
    {
        while (n < c)
        {
            n = n * 2ll;
        }
        tree.assign(2ll * n, {0, 0});
    }
    void set(char c, lol i, lol x, lol lx, lol rx)
    {
        if (rx - lx == 1)
        {
            if (c == '(')
            {
                tree[x] = {1, 0};
            }
            else
                tree[x] = {0, 1};
            return;
        }
        lol m = (lx + rx) / 2;
        if (i < m)
            set(c, i, 2 * x + 1, lx, m);
        else
            set(c, i, 2 * x + 2, m, rx);
        lol a = min(tree[2 * x + 1].first, tree[2 * x + 2].second);
        tree[x] = {tree[2 * x + 1].first + tree[2 * x + 2].first - a,
                   tree[2 * x + 1].second + tree[2 * x + 2].second - a};
    }
    void set(char c, lol i)
    {
        set(c, i, 0, 0, n);
    }
    pair<lol, lol> sum(lol l, lol r, lol x, lol lx, lol rx)
    {
        if (lx >= l && rx <= r)
            return tree[x];
        if (lx >= r || rx <= l)
            return {0, 0};
        lol m = (lx + rx) / 2;
        pair<lol, lol> a = sum(l, r, 2 * x + 1, lx, m);
        pair<lol, lol> b = sum(l, r, 2 * x + 2, m, rx);
        lol c = min(a.first, b.second);
        return {a.first + b.first - c, a.second + b.second - c};
    }
    lol sum(lol l, lol r)
    {
        pair<lol, lol> a = sum(l, r, 0, 0, n);
        return r - l - a.first - a.second;
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    lol m;
    cin >> m;
    segTree q(s.size());
    for (lol i = 0; i < s.size(); i++)
    {
        q.set(s[i], i);
    }

    while (m--)
    {
        lol l, r;
        cin >> l >> r;
        l--;
        cout << q.sum(l, r) << endl;
    }

    return 0;
}