#include <bits/stdc++.h>
#define lol long long
using namespace std;
class segtree
{
public:
    vector<lol> tree, lazy;
    lol n = 1;
    segtree(lol c)
    {
        while (n < c)
            n = n * 2ll;
        tree.assign(2ll * n, 0);
        lazy.assign(2ll * n, 0);
    }
    void propagate(lol x, lol lx, lol rx)
    {
        tree[x] += lazy[x] * 1ll * (rx - lx);
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
    lol n;
    cin >> n;
    lol cn = 1;
    segtree s(n + 1);
    while (n--)
    {
        lol t;
        cin >> t;
        if (t == 1)
        {
            lol x, a;
            cin >> a >> x;
            s.set(0, a, x);
        }
        else if (t == 2)
        {
            lol x;
            cin >> x;
            s.set(cn, cn + 1, x);
            cn++;
        }
        else
        {
            s.set(cn - 1, cn, -s.sum(cn - 1, cn));
            cn--;
        }
        cout << fixed << setprecision(10) << (s.sum(0, cn) / (long double)cn) << endl;
    }

    return 0;
}