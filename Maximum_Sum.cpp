#include <bits/stdc++.h>
#define lol long long
using namespace std;
class segtree
{
public:
    vector<pair<lol, lol>> tree;
    lol n = 1;
    segtree(lol c)
    {
        while (n < c)
            n = n * 2ll;
        tree.assign(2ll * n, {LONG_LONG_MIN, LONG_LONG_MIN});
    }
    void set(lol i, lol v, lol x, lol lx, lol rx)
    {
        if (rx - lx == 1)
        {
            tree[x].first = v;
            tree[x].second = LONG_LONG_MIN;
            return;
        }
        lol m = (lx + rx) / 2;
        if (i < m)
        {
            set(i, v, 2 * x + 1, lx, m);
        }
        else
            set(i, v, 2 * x + 2, m, rx);
        tree[x].first = max(tree[2 * x + 1].first, tree[2 * x + 2].first);
        tree[x].second = max(min(tree[2 * x + 1].first, tree[2 * x + 2].first), max(tree[2 * x + 1].second, tree[2 * x + 2].second));
    }
    void set(lol i, lol v)
    {
        set(i, v, 0, 0, n);
    }
    pair<lol, lol> mx(lol l, lol r, lol x, lol lx, lol rx)
    {
        if (lx >= l && rx <= r)
        {
            return tree[x];
        }
        if (lx >= r || rx <= l)
            return {LONG_LONG_MIN, LONG_LONG_MIN};
        lol m = (lx + rx) / 2;
        pair<lol, lol> a = mx(l, r, 2 * x + 1, lx, m);
        pair<lol, lol> b = mx(l, r, 2 * x + 2, m, rx);
        return {max(a.first, b.first), max(min(a.first, b.first), max(a.second, b.second))};
    }
    pair<lol, lol> mx(lol l, lol r)
    {
        return mx(l, r, 0, 0, n);
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol a[n];
    segtree s(n);
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        s.set(i, a[i]);
    }
    lol q;
    cin >> q;
    while (q--)
    {
        char c;
        cin >> c;
        if (c == 'U')
        {
            lol i, x;
            cin >> i >> x;
            i--;
            s.set(i, x);
        }
        else
        {
            lol l, r;
            cin >> l >> r;
            l--;
            pair<lol, lol> a = s.mx(l, r);
            cout << a.first + a.second << endl;
        }
    }

    return 0;
}