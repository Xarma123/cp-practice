#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol m = 1e9 + 7;

class segmentTree
{
public:
    vector<lol> seg;
    vector<lol> lazy;
    lol size;
    segmentTree(lol n)
    {
        size = 1;
        while (size < n)
            size *= 2;
        seg.assign(2 * size, 0);
        lazy.assign(2 * size, 1);
        for (lol i = 0; i < n; i++)
        {
            set(i, 1, 0, 0, size);
        }
    }
    void set(lol i, lol v, lol x, lol lx, lol rx)
    {
        if (rx - lx == 1)
        {
            seg[x] = v;
            return;
        }
        lol md = (lx + rx) / 2;
        if (i < md)
            set(i, v, 2 * x + 1, lx, md);
        else
            set(i, v, 2 * x + 2, md, rx);
        seg[x] = (seg[2 * x + 2] + seg[2 * x + 1]) % m;
    }
    void add(lol l, lol r, lol v)
    {
        add(l, r, v, 0, 0, size);
    }
    void add(lol l, lol r, lol v, lol x, lol lx, lol rx)
    {
        if (lazy[x] != 1)
        {
            seg[x] *= lazy[x];
            seg[x] %= m;
            if (rx - lx != 1)
            {
                lazy[2 * x + 1] *= lazy[x];
                lazy[2 * x + 1] %= m;
                lazy[2 * x + 2] *= lazy[x];
                lazy[2 * x + 2] %= m;
            }
            lazy[x] = 1;
        }
        if (lx >= r || rx <= l)
            return;
        if (lx >= l && rx <= r)
        {
            seg[x] *= v;
            seg[x] %= m;
            if (rx - lx != 1)
            {
                lazy[2 * x + 1] *= v;
                lazy[2 * x + 1] %= m;
                lazy[2 * x + 2] *= v;
                lazy[2 * x + 2] %= m;
            }
            return;
        }
        lol md = (lx + rx) / 2;
        add(l, r, v, 2 * x + 1, lx, md);
        add(l, r, v, 2 * x + 2, md, rx);
        seg[x] = (seg[2 * x + 1] + seg[2 * x + 2]) % m;
    }
    lol sum(lol l, lol r)
    {
        return sum(l, r, 0, 0, size);
    }
    lol sum(lol l, lol r, lol x, lol lx, lol rx)
    {
        if (lazy[x] != 1)
        {
            seg[x] *= lazy[x];
            seg[x] %= m;
            if (rx - lx != 1)
            {
                lazy[2 * x + 1] *= lazy[x];
                lazy[2 * x + 1] %= m;
                lazy[2 * x + 2] *= lazy[x];
                lazy[2 * x + 2] %= m;
            }
            lazy[x] = 1;
        }
        if (lx >= r || rx <= l)
            return 0;
        if (lx >= l && rx <= r)
        {
            return seg[x];
        }
        lol md = (lx + rx) / 2;
        return (sum(l, r, 2 * x + 1, lx, md) + sum(l, r, 2 * x + 2, md, rx)) % m;
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, q;
    cin >> n >> q;
    segmentTree s(n);
    while (q--)
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
            cout << s.sum(l, r) << endl;
        }
    }

    return 0;
}