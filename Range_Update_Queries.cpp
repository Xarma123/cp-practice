#include <bits/stdc++.h>
using namespace std;
#define lol long long
class segtree
{
public:
    vector<lol> seg;
    vector<lol> lazy;
    lol n;
    segtree(lol c)
    {
        n = 1;
        while (n < c)
            n = n * 2ll;
        seg.assign(2ll * n, 0ll);
        lazy.assign(2ll * n, 0ll);
    }
    void propagate(lol x, lol lx, lol rx)
    {

        seg[x] += (rx - lx) * 1ll * lazy[x];
        if (rx - lx == 1)
        {
            lazy[x] = 0;
            return;
        }
        lazy[2ll * x + 1] += lazy[x];
        lazy[2ll * x + 2] += lazy[x];
        lazy[x] = 0;
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
        lol m = (lx + rx) / 2;
        add(l, r, v, 2 * x + 1, lx, m);
        add(l, r, v, 2 * x + 2, m, rx);
        seg[x] = seg[2 * x + 1] + seg[2 * x + 2];
    }
    void add(lol l, lol r, lol v)
    {
        add(l, r, v, 0, 0, n);
    }
    lol sum(lol l, lol r, lol x, lol lx, lol rx)
    {
        propagate(x, lx, rx);
        if (lx >= l && rx <= r)
            return seg[x];
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
    lol n, q;
    cin >> n >> q;
    lol a[n];
    segtree s(n);
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        s.add(i, i + 1, a[i]);
    }
    while (q--)
    {
        lol t;
        cin >> t;
        if (t == 1)
        {
            lol l, r, v;
            cin >> l >> r >> v;
            l--;
            s.add(l, r, v);
        }
        else
        {
            lol i;
            cin >> i;
            i--;
            cout << s.sum(i, i + 1) << '\n';
        }
    }
}