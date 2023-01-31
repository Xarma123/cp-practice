#include <bits/stdc++.h>
#define lol long long
using namespace std;
struct node
{
    lol pre;
    lol suf;
    lol mxs;
    lol sum;
};

class segTree
{
public:
    lol n = 1;
    vector<node> tree;
    segTree(lol c)
    {
        while (n < c)
            n = 2ll * n;
        tree.assign(2ll * n, {0, 0, 0});
    }
    void set(lol i, lol v, lol x, lol lx, lol rx)
    {
        if (rx - lx == 1)
        {
            tree[x].mxs = v;
            tree[x].pre = v;
            tree[x].suf = v;
            tree[x].sum = v;
            return;
        }
        lol m = (lx + rx) / 2;
        if (i < m)
        {
            set(i, v, 2 * x + 1, lx, m);
        }
        else
            set(i, v, 2 * x + 2, m, rx);
        tree[x] = {
            max(tree[2 * x + 1].sum + tree[2 * x + 2].sum, max(tree[2 * x + 1].sum + tree[2 * x + 2].pre, tree[2 * x + 1].pre)),
            max(tree[2 * x + 1].sum + tree[2 * x + 2].sum, max(tree[2 * x + 2].sum + tree[2 * x + 1].suf, tree[2 * x + 2].suf)),
            max(tree[2 * x + 1].mxs, max(tree[2 * x + 2].mxs, tree[2 * x + 1].suf + tree[2 * x + 2].pre)),
            tree[2 * x + 1].sum + tree[2 * x + 2].sum};
    }
    void set(lol i, lol v)
    {
        set(i, v, 0, 0, n);
    }
    node mx(lol lf, lol rt, lol x, lol lx, lol rx)
    {
        if (lx >= rt || rx <= lf)
        {
            return {LONG_LONG_MIN, LONG_LONG_MIN, LONG_LONG_MIN, LONG_LONG_MIN};
        }
        if (lx >= lf && rx <= rt)
        {
            return tree[x];
        }
        lol m = (lx + rx) / 2;
        node l = mx(lf, rt, 2 * x + 1, lx, m);
        node r = mx(lf, rt, 2 * x + 2, m, rx);
        if (l.mxs == LONG_LONG_MIN)
            return r;
        if (r.mxs == LONG_LONG_MIN)
            return l;
        node q;
        q.sum = l.sum + r.sum;
        q.pre = max(l.pre, max(l.sum + r.sum, l.sum + r.pre));
        q.suf = max(r.suf, max(r.sum + l.sum, r.sum + l.suf));
        q.mxs = max(l.mxs, max(r.mxs, l.suf + r.pre));
        return q;
    }
    lol mx(lol l, lol r)
    {
        return mx(l, r, 0, 0, n).mxs;
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    segTree s(n);
    for (lol i = 0; i < n; i++)
    {
        lol q;
        cin >> q;
        s.set(i, q);
    }
    lol m;
    cin >> m;
    while (m--)
    {
        lol c;
        cin >> c;
        if (c)
        {
            lol l, r;
            cin >> l >> r;
            l--;
            cout << s.mx(l, r) << '\n';
        }
        else
        {
            lol x, y;
            cin >> x >> y;
            s.set(x - 1, y);
        }
    }

    return 0;
}