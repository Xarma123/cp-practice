#include <bits/stdc++.h>
#define lol long long
using namespace std;
class SegmentTree
{
public:
    vector<lol> seg;
    lol size;
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
    lol set(lol i, lol v)
    {
        set(i, v, 0, 0, size);
    }
    lol set(lol i, lol v, lol x, lol lx, lol rx)
    {
        if (rx - lx == 1)
        {
            seg[x] = v;
            return 1;
        }
        lol m = (lx + rx) / 2;
        lol t;
        if (i < m)
            t = set(i, v, 2 * x + 1, lx, m);
        else
            t = set(i, v, 2 * x + 2, m, rx);
        if (t)
        {
            seg[x] = seg[2 * x + 1] | seg[2 * x + 2];
            return 0;
        }
        else
        {
            seg[x] = seg[2 * x + 1] ^ seg[2 * x + 2];
            return 1;
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
    for (lol i = 0; i < (1 << n); i++)
    {
        lol t;
        cin >> t;
        a.push_back(t);
    }
    SegmentTree s(a);
    while (m--)
    {
        lol i, v;
        cin >> i >> v;
        i--;
        s.set(i, v);
        cout << s.seg[0] << endl;
    }

    return 0;
}