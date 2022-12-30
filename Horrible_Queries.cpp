#include <bits/stdc++.h>
#define lol long long
using namespace std;
class segTree
{
public:
    vector<lol> tree, lazy;
    lol n;
    segTree(lol c)
    {
        n = 1;
        while (n < c)
            n = n * 2ll;
        tree.assign(2ll * n, 0);
        lazy.assign(2ll * n, 0);
    }
    void propagate(lol x, lol lx, lol rx)
    {
        tree[x] += (rx - lx) * 1ll * lazy[x];
        if (rx - lx != 1)
        {
            lazy[2 * x + 1] += lazy[x];
            lazy[2 * x + 2] += lazy[x];
        }
        lazy[x] = 0;
    }
    void set(lol l, lol r, lol v, lol x, lol lx, lol rx)
    {
        propagate(x, lx, rx);
        if (lx >= l && rx <= r)
        {
            lazy[x] += v;
            propagate(x, lx, rx);
            return;
        }
        if (lx >= r || rx <= l)
        {
            return;
        }
        lol m = (lx + rx) / 2;
        set(l, r, v, 2 * x + 1, lx, m);
        set(l, r, v, 2 * x + 2, m, rx);
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }
    void set(lol l, lol r, lol v)
    {
        set(l, r, v, 0, 0, n);
    }
    lol sum(lol l, lol r, lol x, lol lx, lol rx)
    {
        propagate(x, lx, rx);
        if (lx >= l && rx <= r)
            return tree[x];
        if (lx >= r || rx <= l)
        {
            return 0;
        }
        lol m = (lx + rx) / 2;
        return sum(l, r, 2 * x + 1, lx, m) + sum(l, r, 2 * x + 2, m, rx);
    }
    lol sum(lol l, lol r)
    {
        return sum(l, r, 0, 0, n);
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, q;
        cin >> n >> q;
        segTree s(n);
        while (q--)
        {
            lol c;
            cin >> c;
            if (c == 0)
            {
                lol l, r, v;
                cin >> l >> r >> v;
                l--;
                s.set(l, r, v);
            }
            else
            {
                lol l, r;
                cin >> l >> r;
                l--;
                cout << s.sum(l, r) << endl;
            }
        }
    }

    return 0;
}