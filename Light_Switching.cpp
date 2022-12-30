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
        if (lazy[x])
        {
            tree[x] = rx - lx - tree[x];
            if (rx - lx != 1)
            {
                lazy[2 * x + 1] = 1 - lazy[2 * x + 1];
                lazy[2 * x + 2] = 1 - lazy[2 * x + 2];
            }
        }
        lazy[x] = 0;
    }
    void set(lol l, lol r, lol x, lol lx, lol rx)
    {
        propagate(x, lx, rx);
        if (lx >= l && rx <= r)
        {
            lazy[x] = 1;
            propagate(x, lx, rx);
            return;
        }
        if (lx >= r || rx <= l)
            return;
        lol m = (lx + rx) / 2;
        set(l, r, 2 * x + 1, lx, m);
        set(l, r, 2 * x + 2, m, rx);
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }
    void set(lol l, lol r)
    {
        set(l, r, 0, 0, n);
    }
    lol sum(lol l, lol r, lol x, lol lx, lol rx)
    {
        propagate(x, lx, rx);
        if (lx >= l && rx <= r)
            return tree[x];
        if (lx >= r || rx <= l)
            return 0;
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
    lol n, m;
    cin >> n >> m;
    segTree s(n);
    while (m--)
    {
        lol c;
        cin >> c;
        if (c == 0)
        {
            lol l, r;
            cin >> l >> r;
            l--;
            s.set(l, r);
        }
        else
        {
            lol l, r;
            cin >> l >> r;
            l--;
            cout << s.sum(l, r) << endl;
        }
    }

    return 0;
}