#include <bits/stdc++.h>
#define lol long long
using namespace std;
class segmentTree
{
public:
    vector<pair<lol, lol>> seg;
    vector<lol> lazy;
    lol size;
    segmentTree(lol n)
    {
        size = 1;
        while (size < n)
            size *= 2;
        seg.assign(2 * size, {0, 0});
        build(0, 0, size);
        lazy.assign(2 * size, 0);
    }
    void build(lol x, lol lx, lol rx)
    {
        if (rx - lx == 1)
        {
            seg[x] = {1, 0};
            return;
        }
        lol m = (lx + rx) / 2;
        build(2 * x + 1, lx, m);
        build(2 * x + 2, m, rx);
        seg[x].first = seg[2 * x + 1].first + seg[2 * x + 2].first;
        seg[x].second = seg[2 * x + 1].second + seg[2 * x + 2].second;
    }
    void add(lol l, lol r)
    {
        add(l, r, 0, 0, size);
    }
    void add(lol l, lol r, lol x, lol lx, lol rx)
    {
        if (lazy[x] != 0)
        {
            if (lazy[x] % 2 != 0)
                swap(seg[x].first, seg[x].second);
            if (rx - lx != 1)
            {
                lazy[2 * x + 1] += lazy[x];
                lazy[2 * x + 2] += lazy[x];
            }
            lazy[x] = 0;
        }
        if (lx >= r || rx <= l)
            return;
        if (lx >= l && rx <= r)
        {
            swap(seg[x].first, seg[x].second);
            if (rx - lx != 1)
            {
                lazy[2 * x + 1]++;
                lazy[2 * x + 2]++;
            }

            return;
        }
        lol m = (lx + rx) / 2;
        add(l, r, 2 * x + 1, lx, m);
        add(l, r, 2 * x + 2, m, rx);
        seg[x].first = seg[2 * x + 1].first + seg[2 * x + 2].first;
        seg[x].second = seg[2 * x + 1].second + seg[2 * x + 2].second;
    }
    lol sum(lol k)
    {
        return sum(k, 0, 0, size);
    }
    void prop(lol x, lol lx, lol rx)
    {
        if (lazy[x] != 0)
        {
            if (lazy[x] % 2 != 0)
                swap(seg[x].first, seg[x].second);
            if (rx - lx != 1)
            {
                lazy[2 * x + 1] += lazy[x];
                lazy[2 * x + 2] += lazy[x];
            }
            lazy[x] = 0;
        }
    }
    lol sum(lol k, lol x, lol lx, lol rx)
    {
        if (lazy[x] != 0)
        {
            if (lazy[x] % 2 != 0)
                swap(seg[x].first, seg[x].second);
            if (rx - lx != 1)
            {
                lazy[2 * x + 1] += lazy[x];
                lazy[2 * x + 2] += lazy[x];
            }
            lazy[x] = 0;
        }
        lol m = (lx + rx) / 2;
        if (seg[x].second < k)
            return -1;
        if (rx - lx == 1)
            return lx;
        prop(2 * x + 1, lx, m);
        prop(2 * x + 2, lx, m);
        if (seg[2 * x + 1].second >= k)
            return sum(k, 2 * x + 1, lx, m);
        else
            return sum(k - seg[2 * x + 1].second, 2 * x + 2, m, rx);
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
        lol c;
        cin >> c;
        if (c == 1)
        {
            lol l, r;
            cin >> l >> r;
            s.add(l, r);
        }
        else
        {
            lol k;
            cin >> k;
            k++;
            cout << s.sum(k) << endl;
        }
    }

    return 0;
}