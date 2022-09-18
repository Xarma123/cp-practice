#include <bits/stdc++.h>
#define lol long long
using namespace std;
struct tri
{
    lol sum;
    lol pre;
    lol suf;
    lol mx;
};

class SegmentTree
{
public:
    lol size;
    vector<tri> seg;
    SegmentTree(lol n)
    {
        size = 1;
        while (size < n)
            size *= 2;
        seg.assign(2 * size, {0, 0, 0, 0});
    }
    void set(lol i, lol v, lol x, lol lx, lol rx)
    {
        if (rx - lx == 1)
        {
            seg[x] = {v, v, v, v};
            return;
        }
        lol m = (lx + rx) / 2;
        if (i < m)
            set(i, v, 2 * x + 1, lx, m);
        else
            set(i, v, 2 * x + 2, m, rx);
        seg[x] = {seg[2 * x + 1].sum + seg[2 * x + 2].sum,

                  max(seg[2 * x + 1].sum + seg[2 * x + 2].sum, max(seg[2 * x + 1].sum + seg[2 * x + 2].pre, seg[2 * x + 1].pre)),
                  max(seg[2 * x + 1].sum + seg[2 * x + 2].sum, max(seg[2 * x + 2].sum + seg[2 * x + 1].suf, seg[2 * x + 2].suf)),
                  max(seg[2 * x + 1].mx, max(seg[2 * x + 2].mx, seg[2 * x + 1].suf + seg[2 * x + 2].pre))};
    }
    void set(lol i, lol v)
    {
        set(i, v, 0, 0, size);
    }
    lol mx()
    {
        return max(seg[0].mx, 0ll);
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
    cout << s.mx() << endl;
    while (m--)
    {
        lol i, v;
        cin >> i >> v;
        s.set(i, v);
        cout << s.mx() << endl;
    }

    return 0;
}