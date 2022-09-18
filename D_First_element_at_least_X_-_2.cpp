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
        seg.assign(2 * size, LONG_LONG_MIN);
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
        seg[x] = max(seg[2 * x + 1], seg[2 * x + 2]);
    }
    lol ans(lol k, lol l)
    {
        return ans(k, l, 0, 0, size);
    }
    lol ans(lol s, lol l, lol x, lol lx, lol rx)
    {
        if (rx <= l)
            return -1;

        if (seg[x] < s)
            return -1;

        if (rx - lx == 1)
        {
            if (lx < l)
                return -1;
            else
                return lx;
        }

        lol s1 = ans(s, l, 2 * x + 1, lx, (lx + rx) / 2);
        if (s1 == -1)
            return ans(s, l, 2 * x + 2, (lx + rx) / 2, rx);
        return s1;
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
            lol i, v;
            cin >> i >> v;

            s.set(i, v);
            a[i] = v;
        }
        else
        {
            lol k, l;
            cin >> k >> l;
            cout << s.ans(k, l) << endl;
        }
    }

    return 0;
}