#include <bits/stdc++.h>
#define lol long long
using namespace std;
class SegmentTree
{
public:
    vector<lol> seg;
    lol size;
    SegmentTree(vector<lol> &a)
    {
        size = 1;
        while (size < a.size())
        {
            size *= 2;
        }
        seg.assign(2 * size, LONG_LONG_MIN);
        for (lol i = 0; i < a.size(); i++)
            set(i, a[i]);
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
            set(i, v, 2 * x + 1, lx, m);
        else
            set(i, v, 2 * x + 2, m, rx);
        seg[x] = max(seg[2 * x + 1], seg[2 * x + 2]);
    }
    lol mx(lol l, lol r)
    {
        return mx(l, r, 0, 0, size);
    }
    lol mx(lol l, lol r, lol x, lol lx, lol rx)
    {
        if (lx >= r || rx <= l)
            return LONG_LONG_MIN;
        if (lx >= l && rx <= r)
            return seg[x];
        lol m = (lx + rx) / 2;
        return max(mx(l, r, 2 * x + 1, lx, m), mx(l, r, 2 * x + 2, m, rx));
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
        lol r;
        cin >> r;
        lol st = -1;
        lol e = n;
        while (st != e - 1)
        {
            lol md = (st + e) / 2;
            if (md == -1)
                st = md;
            else if (md == n)
                e = md;
            else if (s.mx(0, md + 1) >= r)
            {
                e = md;
            }
            else
                st = md;
        }
        if (e == n)
            cout << 0 << " ";
        else
        {
            cout << e + 1 << " ";
            a[e] -= r;
            s.set(e, a[e]);
        }
    }

    return 0;
}