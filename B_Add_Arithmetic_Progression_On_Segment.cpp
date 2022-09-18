#include <bits/stdc++.h>
#define lol long long
using namespace std;
class segmentTree
{
public:
    vector<pair<lol, lol>> lazy;
    vector<lol> seg;
    lol size;
    segmentTree(lol n)
    {
        size = 1;
        while (size < n)
            size *= 2;
        lazy.assign(2 * size, {0, 0});
        seg.assign(2 * size, 0ll);
    }
    void propagate(lol x, lol lx, lol rx)
    {
        if (lazy[x].first == 0)
            return;
        if (rx - lx == 1)
        {
            lazy[x] = {0, 0};
            return;
        }
        lol m = (lx + rx) / 2;
        lol a = lazy[x].first;
        lol d = lazy[x].second;
        seg[2 * x + 1] += (m - lx) * (2 * a + (m - lx - 1) * d) / 2;
        lazy[2 * x + 1].first += a;
        lazy[2 * x + 1].second += d;
        a = lazy[x].first + (m - lx) * (lazy[x].second);
        d = lazy[x].second;
        seg[2 * x + 2] += (rx - m) * (2 * a + (rx - m - 1) * d) / 2;
        lazy[2 * x + 2].first += a;
        lazy[2 * x + 2].second += d;

        lazy[x] = {0, 0};
    }
    void add(lol l, lol r, lol a, lol d, lol x, lol lx, lol rx)
    {
        propagate(x, lx, rx);
        if (lx >= r || l >= rx)
            return;
        if (lx >= l && rx <= r)
        {
            lol A = a + d * (lx - l);
            lazy[x].first += A;
            lazy[x].second += d;
            seg[x] += (rx - lx) * (2 * A + (rx - lx - 1) * d) / 2;
            return;
        }
        lol m = (lx + rx) / 2;
        add(l, r, a, d, 2 * x + 1, lx, m);
        add(l, r, a, d, 2 * x + 2, m, rx);
        seg[x] = seg[2 * x + 1] + seg[2 * x + 2];
    }

    void add(lol l, lol r, lol a, lol d)
    {
        add(l, r, a, d, 0, 0, size);
    }
    lol sum(lol l, lol r)
    {
        return sum(l, r, 0, 0, size);
    }
    lol sum(lol l, lol r, lol x, lol lx, lol rx)
    {
        propagate(x, lx, rx);
        if (rx <= l || lx >= r)
            return 0;
        if (rx <= r && lx >= l)
            return seg[x];
        lol m = (lx + rx) / 2;
        return sum(l, r, 2 * x + 1, lx, m) + sum(l, r, 2 * x + 2, m, rx);
    }
};

int main()
{
    lol n, m;
    cin >> n >> m;

    segmentTree s(n);

    while (m--)
    {
        lol c;
        cin >> c;
        if (c == 1)
        {
            lol l, r, a, d;
            cin >> l >> r >> a >> d;
            l--;
            s.add(l, r, a, d);
        }
        else
        {

            lol l;
            cin >> l;
            l--;
            lol res = s.sum(l, l + 1);
            cout << res << "\n";
        }
    }
    return 0;
}