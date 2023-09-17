#include <bits/stdc++.h>
using namespace std;
#define lol long long
class segtree
{
public:
    vector<lol> seg;
    lol n;
    segtree(lol c)
    {
        n = 1;
        while (n < c)
            n = n * 2ll;
        seg.assign(2ll * n, LONG_LONG_MAX);
    }
    void set(lol i, lol v, lol x, lol lx, lol rx)
    {
        if (rx - lx == 1)
        {
            seg[x] = v;
            return;
        }
        lol m = (lx + rx) / 2;
        if (i < m)
        {
            set(i, v, 2ll * x + 1, lx, m);
        }
        else
            set(i, v, 2ll * x + 2, m, rx);
        seg[x] = min(seg[2ll * x + 1], seg[2ll * x + 2]);
    }
    void set(lol i, lol v)
    {
        set(i, v, 0, 0, n);
    }
    lol mn(lol l, lol r, lol x, lol lx, lol rx)
    {
        if (lx >= l && rx <= r)
            return seg[x];
        if (lx >= r || rx <= l)
        {
            return LONG_LONG_MAX;
        }
        lol m = (lx + rx) / 2;
        return min(mn(l, r, 2ll * x + 1, lx, m), mn(l, r, 2 * x + 2, m, rx));
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
    lol n, q;
    cin >> n >> q;
    segtree s(n);
    for (lol i = 0; i < n; i++)
    {
        lol v;
        cin >> v;
        s.set(i, v);
    }
    while (q--)
    {
        lol t;
        cin >> t;
        if (t == 1)
        {
            lol i, v;
            cin >> i >> v;
            i--;
            s.set(i, v);
        }
        else
        {
            lol l, r;
            cin >> l >> r;
            l--;
            cout << s.mn(l, r) << '\n';
        }
    }
}