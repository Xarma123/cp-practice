#include <bits/stdc++.h>
#define lol long long
using namespace std;
class segTree
{
public:
    vector<lol> tree, lazy;
    lol n = 1;
    segTree(lol c)
    {
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
            return;
        lol m = (lx + rx) / 2;
        set(l, r, v, 2 * x + 1, lx, m);
        set(l, r, v, 2 * x + 2, m, rx);
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }
    void set(lol l, lol r, lol v)
    {
        set(l, r, v, 0, 0, n);
    }
    lol mn(lol l, lol r, lol x, lol lx, lol rx)
    {
        propagate(x, lx, rx);
        if (lx >= l && rx <= r)
            return tree[x];
        if (lx >= r || rx <= l)
            return 0;
        lol m = (lx + rx) / 2;
        return mn(l, r, 2 * x + 1, lx, m) + mn(l, r, 2 * x + 2, m, rx);
    }
    lol mn(lol l, lol r)
    {
        return mn(l, r, 0, 0, n);
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
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        segTree s(n);
        while (q--)
        {
            lol c;
            cin >> c;
            if (c == 1)
            {
                lol l, r;
                cin >> l >> r;
                l--;
                s.set(l, r, 1);
            }
            else
            {
                lol x;
                cin >> x;
                x--;
                lol w = s.mn(x, x + 1);
                string q = to_string(a[x]);
                while (q.size() > 1 && w--)
                {
                    lol v = 0;
                    for (auto e : q)
                        v += (e - '0');
                    q = to_string(v);
                }
                cout << q << '\n';
            }
        }
    }

    return 0;
}