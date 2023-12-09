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
        lol m = (lx + rx) / 2ll;
        set(l, r, v, 2ll * x + 1, lx, m);
        set(l, r, v, 2ll * x + 2, m, rx);
        seg[x] = max(seg[2ll * x + 1], seg[2ll * x + 2]);
    }
    void set(lol l, lol r, lol v)
    {
        set(l, r, v, 0, 0, n);
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol q;
    cin >> q;
    vector<pair<char, pair<lol, lol>>> v;
    set<lol> x;
    while (q--)
    {
        char c;
        cin >> c;
        lol l, r;
        cin >> l >> r;
        v.push_back({c, {l, r}});
        x.insert(l);
        x.insert(r);
    }
    vector<lol> a;
    for (auto e : x)
        a.push_back(e);
    sort(a.begin(), a.end());
    segtree s(a.size());
    lol tot = 0;
    for (auto e : v)
    {
        char c = e.first;
        lol l = e.second.first;
        lol r = e.second.second;
        lol j1 = lower_bound(a.begin(), a.end(), l) - a.begin();
        lol j2 = lower_bound(a.begin(), a.end(), r) - a.begin();
        if (c == '+')
            s.set(j1, j2+1, 1), tot++;
        else
            s.set(j1, j2+1, -1), tot--;
        
        if (s.seg[0] < tot)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
