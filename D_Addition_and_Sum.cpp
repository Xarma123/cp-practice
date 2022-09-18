#include <bits/stdc++.h>
#define lol long long
using namespace std;
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
        lazy.assign(2 * size, 0);
    }
    void add(lol l, lol r, lol v)
    {
        add(l, r, v, 0, 0, size);
    }
    void add(lol l, lol r, lol v, lol x, lol lx, lol rx)
    {
        if (lazy[x] != 0)
        {
            seg[x] += lazy[x] * (rx - lx);
            if (rx - lx != 1)
            {
                lazy[2 * x + 1] += lazy[x];
                lazy[2 * x + 2] += lazy[x];
            }
            lazy[x] = 0;
        }
        if (lx >= r || rx <= l)
            return;
        if (lx >= l && rx <= r)
        {
            seg[x] += v * (rx - lx);
            if (rx - lx != 1)
            {
                lazy[2 * x + 1] += v;
                lazy[2 * x + 2] += v;
            }
            return;
        }
        lol m = (lx + rx) / 2;
        add(l, r, v, 2 * x + 1, lx, m);
        add(l, r, v, 2 * x + 2, m, rx);
        seg[x] = seg[2 * x + 1] + seg[2 * x + 2];
    }
    lol sum(lol l, lol r)
    {
        return sum(l, r, 0, 0, size);
    }
    lol sum(lol l, lol r, lol x, lol lx, lol rx)
    {
        if (lazy[x] != 0)
        {
            seg[x] += lazy[x] * (rx - lx);
            if (rx - lx != 1)
            {
                lazy[2 * x + 1] += lazy[x];
                lazy[2 * x + 2] += lazy[x];
            }
            lazy[x] = 0;
        }
        if (lx >= r || rx <= l)
            return 0;
        if (lx >= l && rx <= r)
        {
            return seg[x];
        }
        lol m = (lx + rx) / 2;
        return sum(l, r, 2 * x + 1, lx, m) + sum(l, r, 2 * x + 2, m, rx);
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    segmentTree s(n);
    while (m--)
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