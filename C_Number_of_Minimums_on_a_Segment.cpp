#include <bits/stdc++.h>
#define lol long long
using namespace std;
class SegmentTree
{
public:
    lol size;
    vector<pair<lol, lol>> seg;
    SegmentTree(vector<lol> x)
    {
        size = 1;
        while (size < x.size())
            size *= 2;
        seg.assign(2 * size, {LONG_LONG_MAX, 1});
        for (lol i = 0; i < x.size(); i++)
        {
            set(i, x[i]);
        }
    }
    void set(lol i, lol v)
    {
        return set(i, v, 0, 0, size);
    }
    void set(lol i, lol v, lol x, lol lx, lol rx)
    {
        if (rx - lx == 1)
        {
            seg[x] = {v, 1};
            return;
        }
        lol m = (lx + rx) / 2;
        if (i < m)
            set(i, v, 2 * x + 1, lx, m);
        else
            set(i, v, 2 * x + 2, m, rx);
        if (seg[2 * x + 1].first == seg[2 * x + 2].first)
            seg[x] = {seg[2 * x + 1].first, seg[2 * x + 1].second + seg[2 * x + 2].second};
        else if (seg[2 * x + 1].first < seg[2 * x + 2].first)
            seg[x] = seg[2 * x + 1];
        else
            seg[x] = seg[2 * x + 2];

        return;
    }
    pair<lol, lol> mn(lol l, lol r)
    {
        return mn(l, r, 0, 0, size);
    }
    pair<lol, lol> mn(lol l, lol r, lol x, lol lx, lol rx)
    {
        if (r <= lx || (l >= rx))
            return {LONG_LONG_MAX, 1};
        if (l <= lx && r >= rx)
            return seg[x];
        lol m = (lx + rx) / 2;
        pair<lol, lol> s1 = mn(l, r, 2 * x + 1, lx, m);
        pair<lol, lol> s2 = mn(l, r, 2 * x + 2, m, rx);
        if (s1.first == s2.first)
            return {s1.first, s1.second + s2.second};
        else if (s1.first < s2.first)
            return {s1.first, s1.second};
        else
            return {s2.first, s2.second};
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
            pair<lol, lol> q = s.mn(x, y);
            cout << q.first << " " << q.second << endl;
        }
    }

    return 0;
}