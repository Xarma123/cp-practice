#include <bits/stdc++.h>
using namespace std;
#define lol long long
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        pair<lol, lol> a[n];
        lol b[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i].first >> a[i].second;
            b[i] = a[i].second;
        }
        sort(a, a + n);
        sort(b, b + n);
        SegmentTree s(n);
        for (lol i = 0; i < n; i++)
        {
            s.set(i, 1);
        }
        lol ans = 0;
        for (lol i = 0; i < n; i++)
        {
            lol j = lower_bound(b, b + n, a[i].second) - b;
            ans += s.sum(0, j);
            s.set(j, 0);
        }
        cout << ans << '\n';
    }

    return 0;
}
