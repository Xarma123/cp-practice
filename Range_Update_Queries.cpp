#include <bits/stdc++.h>
#define lol long long
using namespace std;
class SegmentTree
{
public:
    vector<lol> seg;
    lol size;
    SegmentTree(lol n)
    {
        size = 1;
        while (size < n)
            size *= 2;
        size *= 2;
        seg.assign(2 * size, 0);
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
        seg[x] = (seg[2 * x + 1] + seg[2 * x + 2]);
    }
    lol sum(lol l, lol r)
    {
        return sum(l, r, 0, 0, size);
    }
    lol sum(lol l, lol r, lol x, lol lx, lol rx)
    {
        if (rx <= l || lx >= r)
            return 0;
        if (lx >= l && rx <= r)
            return seg[x];
        lol m = (lx + rx) / 2;
        return (sum(l, r, 2 * x + 1, lx, m) + sum(l, r, 2 * x + 2, m, rx));
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, q;
    cin >> n >> q;
    vector<lol> a;
    for (lol i = 0; i < n; i++)
    {
        lol t;
        cin >> t;
        a.push_back(t);
    }
    SegmentTree s(a.size());
    while (q--)
    {
        lol c;
        cin >> c;
        if (c == 1)
        {
            lol a, b, u;
            cin >> a >> b >> u;
            a--;
            s.set(a, u + s.sum(a, a + 1));
            s.set(b, -u + s.sum(b, b + 1));
        }
        else
        {
            lol k;
            cin >> k;
            cout << s.sum(0, k) + a[k - 1] << endl;
        }
    }

    return 0;
}