#include <bits/stdc++.h>
using namespace std;
#define lol long long
class segtree
{
public:
    vector<lol>
        seg, lazy;
    lol n;
    segtree(lol c)
    {
        n = 1;
        while (n < c)
        {
            n = n * 2ll;
        }
        seg.assign(2ll * n, 0);
        lazy.assign(2ll * n, 0);
    }
    void propagate(lol x, lol lx, lol rx)
    {
        seg[x] += lazy[x];
        if (rx - lx != 1)
        {
            lazy[2ll * x + 1] += lazy[x];
            lazy[2ll * x + 2] += lazy[x];
        }
        lazy[x] = 0;
        return;
    }
    void add(lol l, lol r, lol v, lol x, lol lx, lol rx)
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
        lol m = (lx + rx) / 2ll;
        add(l, r, v, 2 * x + 1, lx, m);
        add(l, r, v, 2 * x + 2, m, rx);
        seg[x] = max(seg[2 * x + 1], seg[2 * x + 2]);
    }
    void add(lol l, lol r, lol v)
    {
        add(l, r, v, 0, 0, n);
    }
    lol mx(lol l, lol r, lol x, lol lx, lol rx)
    {
        propagate(x, lx, rx);
        if (lx >= l && rx <= r)
            return seg[x];
        if (lx >= r || rx <= l)
            return LONG_LONG_MIN;
        lol m = (lx + rx) / 2ll;
        return max(mx(l, r, 2 * x + 1, lx, m), mx(l, r, 2 * x + 2, m, rx));
    }
    lol mx(lol l, lol r)
    {
        return mx(l, r, 0, 0, n);
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    segtree s(2);
    while (1)
    {
        lol c;
        cin >> c;
        if (c == 1)
        {
            lol l, r, v;
            cin >> l >> r >> v;
            s.add(l, r, v);
        }
        else
        {
            lol l, r;
            cin >> l >> r;
            cout << s.mx(l, r) << endl;
        }
    }

    return 0;
}
