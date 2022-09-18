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
        seg[x] = seg[2 * x + 1] + seg[2 * x + 2];
    }
    lol ans(lol k)
    {
        return ans(k + 1, 0, 0, size);
    }
    lol ans(lol s, lol x, lol lx, lol rx)
    {
        if (rx - lx == 1)
        {
            return lx;
        }
        if (seg[2 * x + 1] >= s)
        {
            return ans(s, 2 * x + 1, lx, (lx + rx) / 2);
        }
        else
        {
            return ans(s - seg[2 * x + 1], 2 * x + 2, (lx + rx) / 2, rx);
        }
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
            lol i;
            cin >> i;

            s.set(i, 1 - a[i]);
            a[i] = 1 - a[i];
        }
        else
        {
            lol k;
            cin >> k;
            cout << s.ans(k) << endl;
        }
    }

    return 0;
}