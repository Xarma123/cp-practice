#include <bits/stdc++.h>
#define lol long long
using namespace std;
class segmentTree
{
public:
    vector<lol> sum;
    vector<lol> pre;
    vector<lol> suf;
    vector<lol> mx;
    vector<lol> lazy;
    lol size;
    segmentTree(lol n)
    {
        size = 1;
        while (size < n)
            size *= 2;
        sum.assign(2 * size, 0);
        pre.assign(2 * size, 0);
        suf.assign(2 * size, 0);
        mx.assign(2 * size, 0);
        lazy.assign(2 * size, LONG_LONG_MAX);
    }
    void add(lol l, lol r, lol v)
    {
        add(l, r, v, 0, 0, size);
    }
    void add(lol l, lol r, lol v, lol x, lol lx, lol rx)
    {
        if (lazy[x] != LONG_LONG_MAX)
        {
            sum[x] = lazy[x] * (rx - lx);
            if (lazy[x] >= 0)
                pre[x] = suf[x] = mx[x] = lazy[x] * (rx - lx);
            else
                pre[x] = suf[x] = mx[x] = 0;
            if (rx - lx != 1)
            {
                lazy[2 * x + 1] = lazy[x];
                lazy[2 * x + 2] = lazy[x];
            }
            lazy[x] = LONG_LONG_MAX;
        }
        if (lx >= r || rx <= l)
            return;
        if (lx >= l && rx <= r)
        {
            sum[x] = v * (rx - lx);
            if (v >= 0)
                pre[x] = suf[x] = mx[x] = v * (rx - lx);
            else
                pre[x] = suf[x] = mx[x] = 0;
            if (rx - lx != 1)
            {
                lazy[2 * x + 1] = v;
                lazy[2 * x + 2] = v;
            }
            return;
        }
        lol m = (lx + rx) / 2;
        add(l, r, v, 2 * x + 1, lx, m);
        add(l, r, v, 2 * x + 2, m, rx);
        sum[x] = sum[2 * x + 1] + sum[2 * x + 2];
        pre[x] = max(pre[2 * x + 1], sum[2 * x + 1] + pre[2 * x + 2]);
        suf[x] = max(suf[2 * x + 2], suf[2 * x + 1] + sum[2 * x + 2]);
        mx[x] = max(suf[2 * x + 1] + pre[2 * x + 2], max(mx[2 * x + 1], mx[2 * x + 2]));
    }
    lol mxsum(lol x)
    {
        if (lazy[x] != LONG_LONG_MAX)
        {
            sum[x] = lazy[x] * (size);
            if (lazy[x] >= 0)
                pre[x] = suf[x] = mx[x] = lazy[x] * (size);
            else
                pre[x] = suf[x] = mx[x] = 0;
            if (size!= 1)
            {
                lazy[2 * x + 1] = lazy[x];
                lazy[2 * x + 2] = lazy[x];
            }
            lazy[x] = LONG_LONG_MAX;
        }
        return mx[x];
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
    while (m--)
    {

        lol l, r, v;
        cin >> l >> r >> v;
        s.add(l, r, v);

        cout << s.mxsum(0) << endl;
    }

    return 0;
}