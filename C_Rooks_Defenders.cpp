#include <bits/stdc++.h>
#define lol long long
using namespace std;
class SegmentTree
{
public:
    lol size;
    vector<lol> seg;
    SegmentTree(lol n)
    {
        size = 1;
        while (size < n)
        {
            size *= 2;
        }
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
        if (seg[2 * x + 1] == 1 && seg[2 * x + 2] == 1)
            seg[x] = 1;
        else
            seg[x] = 0;
    }
    lol sum(lol l, lol r)
    {
        return sum(l, r, 0, 0, size);
    }
    lol sum(lol l, lol r, lol x, lol lx, lol rx)
    {
        if (rx <= l || lx >= r)
            return 1;

        if (lx >= l && rx <= r)
            return seg[x];
        lol m = (lx + rx) / 2;
        lol v1 = sum(l, r, 2 * x + 1, lx, m);
        lol v2 = sum(l, r, 2 * x + 2, m, rx);
        if (v1 == 1 && v2 == 1)
            return 1;
        else
            return 0;
    }
    
};
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, q;
    cin >> n >> q;
    map<lol, lol> mp;
    map<lol, lol> mp1;
    SegmentTree srow(n);
    SegmentTree scol(n);
    while (q--)
    {
       
        lol t;
        cin >> t;
        if (t == 1)
        {
            lol x, y;
            cin >> x >> y;
            x--;
            y--;
            srow.set(x, 1);
            scol.set(y, 1);
            mp[x]++;
            mp1[y]++;
        }
        else if (t == 2)
        {
            lol x, y;
            cin >> x >> y;
            x--;
            y--;
            mp[x]--;
            if (mp[x] == 0)
                srow.set(x, 0);
            mp1[y]--;
            if (mp1[y] == 0)
                scol.set(y, 0);
        }
        else if (t == 3)
        {
            lol x1, x2, y1, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            x1--;

            y1--;

            if (srow.sum(x1, x2) == 1 || scol.sum(y1, y2) == 1)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }

    return 0;
}