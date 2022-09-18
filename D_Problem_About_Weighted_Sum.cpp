#include <bits/stdc++.h>
#define lol long long
using namespace std;
class segmentTree
{
public:
    lol size;
    vector<lol> sum;
    vector<lol> wsum;
    vector<lol> lazy;
    segmentTree(lol n)
    {
        size = 1;
        while (size < n)
        {
            size *= 2;
        }
        sum.assign(2 * size, 0);
        wsum.assign(2 * size, 0);
        lazy.assign(2 * size, 0);
    }
    void propagate(lol x, lol lx, lol rx)
    {
        if (lazy[x] == 0 || rx - lx == 1)
        {
            lazy[x] = 0;
            return;
        }
        lol m = (lx + rx) / 2;
        sum[2 * x + 1] += lazy[x] * (m - lx);
        wsum[2 * x + 1] += lazy[x] * (m - lx) * (m + lx + 1) / 2;
        lazy[2 * x + 1] += lazy[x];
        sum[2 * x + 2] += lazy[x] * (rx - m);
        wsum[2 * x + 2] += lazy[x] * (rx - m) * (rx + m + 1) / 2;
        lazy[2 * x + 2] += lazy[x];
        lazy[x] = 0;
    }
    void add(lol l, lol r, lol v)
    {
        add(l, r, v, 0, 0, size);
    }
    void add(lol l, lol r, lol v, lol x, lol lx, lol rx)
    {
        propagate(x, lx, rx);
        if (lx >= r || rx <= l)
            return;
        if (lx >= l && rx <= r)
        {
            lazy[x] = v;
            sum[x] += v * (rx - lx);
            wsum[x] += v * (rx - lx) * (lx + rx + 1) / 2;
            return;
        }
        lol m = (lx + rx) / 2;
        add(l, r, v, 2 * x + 1, lx, m);
        add(l, r, v, 2 * x + 2, m, rx);
        sum[x] = sum[2 * x + 1] + sum[2 * x + 2];
        wsum[x] = wsum[2 * x + 1] + wsum[2 * x + 2];
        return;
    }
    lol ans(lol l, lol r)
    {
        pair<lol, lol> x = ans(l, r, 0, 0, size);
        return x.second - x.first * (l);
    }
    pair<lol, lol> ans(lol l, lol r, lol x, lol lx, lol rx)
    {
        propagate(x, lx, rx);
        if (rx <= l || lx >= r)
            return {0, 0};
        if (lx >= l && rx <= r)
            return {sum[x], wsum[x]};
        lol m = (lx + rx) / 2;
        pair<lol, lol> a = ans(l, r, 2 * x + 1, lx, m);
        pair<lol, lol> b = ans(l, r, 2 * x + 2, m, rx);
        return {a.first + b.first, a.second + b.second};
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
    for (lol i = 0; i < n; i++)
    {
        lol t;
        cin >> t;
        s.add(i, i + 1, t);
    }
    while (m--)
    {
        lol c;
        cin >> c;
        if (c == 1)
        {
            lol l, r, v;
            cin >> l >> r >> v;
            l--;
            s.add(l, r, v);
        }
        else
        {
            lol l, r;
            cin >> l >> r;
            l--;
            cout << s.ans(l, r) << endl;
        }
    }

    return 0;
}