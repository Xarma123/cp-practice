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
    SegmentTree(vector<lol> &a)
    {
        size = 1;
        while (size < a.size())
            size *= 2;
        seg.assign(2 * size, {0, 0, 0, 0});
        for (lol i = 0; i < a.size(); i++)
        {
            set(i, a[i]);
        }
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

    tri maxsum(lol l, lol r)
    {
        if (l >= r)
            return {0, 0, 0, 0};
        return maxsum(l, r, 0, 0, size);
    }
    tri maxsum(lol l, lol r, lol x, lol lx, lol rx)
    {
        if (lx >= l && rx <= r)
        {
            return seg[x];
        }
        if (lx >= r || rx <= l)
            return {0, 0, 0, 0};
        lol m = (lx + rx) / 2;
        tri left = maxsum(l, r, 2 * x + 1, lx, m);
        tri right = maxsum(l, r, 2 * x + 2, m, rx);
        return {
            left.sum + right.sum,
            max(left.sum + right.pre, left.pre),
            max(right.suf, right.sum + left.suf),
            max(left.mx, max(right.mx, left.suf + right.pre))

        };
    }
};
vector<pair<lol, lol>> pre_nex_gr(vector<lol> &a)
{
    stack<pair<lol, lol>> s;
    s.push({LONG_LONG_MAX, -1});
    vector<pair<lol, lol>> ans(a.size(), {-1, -1});
    for (lol i = 0; i < a.size(); i++)
    {
        while (s.top().first <= a[i])
        {
            pair<lol, lol> x = s.top();
            s.pop();
            ans[x.second].first = s.top().second;
            ans[x.second].second = i;
        }
        s.push({a[i], i});
    }
    while (s.size() > 1)
    {
        pair<lol, lol> x = s.top();
        s.pop();
        ans[x.second].first = s.top().second;
        ans[x.second].second = a.size();
    }
    return ans;
}