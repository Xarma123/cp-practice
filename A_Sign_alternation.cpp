#include <bits/stdc++.h>
#define lol long long
using namespace std;
class SegmentTree
{
public:
    lol size;
    vector<lol> seg;
    SegmentTree(vector<lol> &a)
    {
        size = 1;
        while (size < a.size())
            size *= 2;
        seg.assign(2 * size, 0);
        for (lol i = 0; i < a.size(); i++)
        {
            set(i, a[i]);
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

            if (lx % 2 == 0)
                seg[x] = v;
            else
                seg[x] = -v;

            return;
        }
        lol m = (lx + rx) / 2;
        if (i < m)
            set(i, v, 2 * x + 1, lx, m);
        else
            set(i, v, 2 * x + 2, m, rx);
        seg[x] = seg[2 * x + 1] + seg[2 * x + 2];
    }
    lol sum(lol l, lol r)
    {
        if (l % 2 == 0)
            return sum(l, r, 0, 0, size);
        else
            return -sum(l, r, 0, 0, size);
    }
    lol sum(lol l, lol r, lol x, lol lx, lol rx)
    {
        if (rx <= l || lx >= r)
            return 0;
        if (lx >= l && rx <= r)
            return seg[x];
        lol m = (lx + rx) / 2;
        return sum(l, r, 2 * x + 1, lx, m) + sum(l, r, 2 * x + 2, m, rx);
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    vector<lol> a;
    for (lol i = 0; i < n; i++)
    {
        lol t;
        cin >> t;
        a.push_back(t);
    }
    SegmentTree s(a);
    lol m;
    cin >> m;
    while (m--)
    {
        lol c;
        cin >> c;
        if (c == 0)
        {
            lol i, v;

            cin >> i >> v;
            i--;
            s.set(i, v);
        }
        else
        {
            lol l, r;
            cin >> l >> r;
            l--;
            cout << s.sum(l, r) << endl;
        }
    }

    return 0;
}