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
        seg.assign(2 * size, 0);
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
            set(i, v, 2 * x + 1, lx, m);
        else
            set(i, v, 2 * x + 2, m, rx);
        seg[x] = seg[2 * x + 1] + seg[2 * x + 2];
    }
    void set(lol i, lol v)
    {
        set(i, v, 0, 0, size);
    }
    lol sum(lol l, lol r)
    {
        return sum(l, r, 0, 0, size);
    }
    lol sum(lol l, lol r, lol x, lol lx, lol rx)
    {
        if (lx >= r || l >= rx)
            return 0;
        if (lx >= l && rx <= r)
            return seg[x];
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
    SegmentTree s(n);

    for (lol i = 0; i < n; i++)
    {
        lol t;
        cin >> t;
        s.set(i, t);
    }
    while (m--)
    {
        lol c;
        cin >> c;
        if (c == 1)
        {
            lol x, y;
            cin >> x >> y;
            s.set(x, y);
        }
        else
        {
            lol x, y;
            cin >> x >> y;
            cout << s.sum(x, y) << endl;
        }
    }

    return 0;
}