#include <bits/stdc++.h>
#define lol long long
using namespace std;
class SegmentTree
{
public:
    lol size;
    vector<lol> seg;
    SegmentTree(vector<lol> x)
    {
        size = 1;
        while (size < x.size())
            size *= 2;
        seg.assign(2 * size, LONG_LONG_MAX);
        for (lol i = 0; i < x.size(); i++)
        {
            set(i, x[i]);
        }
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
        if(i<m)
        set(i, v, 2 * x + 1, lx, m);
        else
        set(i, v, 2 * x + 2, m, rx);
        seg[x] = min(seg[2 * x + 1], seg[2 * x + 2]);
        return;
    }
    lol mn(lol l, lol r)
    {
        return mn(l, r, 0, 0, size);
    }
    lol mn(lol l, lol r, lol x, lol lx, lol rx)
    {
        if (r <= lx || (l >= rx))
            return LONG_LONG_MAX;
        if (l <= lx && r >= rx)
            return seg[x];
        lol m = (lx + rx) / 2;
        return min(mn(l, r, 2 * x + 1, lx, m), mn(l, r, 2 * x + 2, m, rx));
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    vector<lol> a;
    for (lol i = 0; i < n; i++)
    {
        lol t;
        cin >> t;
        a.push_back(t);
    }
    SegmentTree s(a);
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
            cout << s.mn(x, y) << endl;
        }
    }

    return 0;
}