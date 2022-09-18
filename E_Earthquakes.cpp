#include <bits/stdc++.h>
#define lol long long
using namespace std;

class SegmentTree
{
public:
    lol size;
    vector<lol> seg;
    SegmentTree(lol n)
    {
        size = 1;
        while (size < n)
            size *= 2;
        seg.assign(2 * size, LONG_LONG_MAX);
    }
    void set(lol i, lol v)
    {
        set(i, v, 0, 0, size);
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
            set(i, v, 2 * x + 1, lx, m);
        }
        else
            set(i, v, 2 * x + 2, m, rx);

        seg[x] = min(seg[2 * x + 1], seg[2 * x + 2]);
    }
    lol sum(lol l, lol r, lol p)
    {
        return sum(l, r, 0, 0, size, p);
    }
    lol sum(lol l, lol r, lol x, lol lx, lol rx, lol p)
    {
        if (seg[x] > p)
            return 0;

        if (rx <= l || lx >= r)
            return 0;
        if (lx >= l && rx <= r)
        {
            if (seg[x] > p)
            {

                return 0;
            }
        }
        if (rx - lx == 1)
        {
            set(lx, LONG_LONG_MAX);
            return 1;
        }

        lol m = (lx + rx) / 2;
        return sum(l, r, 2 * x + 1, lx, m, p) + sum(l, r, 2 * x + 2, m, rx, p);
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    SegmentTree s(n);
    while (m--)
    {
        lol c;
        cin >> c;
        if (c == 1)
        {

            lol i, h;
            cin >> i >> h;

            s.set(i, h);
        }
        else
        {
            lol l, r, p;
            cin >> l >> r >> p;

            cout << s.sum(l, r, p) << endl;
        }
    }

    return 0;
}