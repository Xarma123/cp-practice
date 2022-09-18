#include <bits/stdc++.h>
#define lol long long
using namespace std;
class SegmentTree
{
public:
    lol size;
    vector<vector<bool>> seg;
    SegmentTree(vector<lol> &a)
    {
        size = 1;
        while (size < a.size())
            size *= 2;
        vector<bool> x;
        x.assign(40, false);
        seg.assign(2 * size, x);
        for (lol i = 0; i < a.size(); i++)
        {
            seti(i, a[i]);
        }
    }
    void seti(lol i, lol v)
    {
        seti(i, v, 0, 0, size);
    }
    void seti(lol i, lol v, lol x, lol lx, lol rx)
    {
        if (rx - lx == 1)
        {
            for (lol j = 0; j < 40; j++)
            {
                if (j != v - 1)
                    seg[x][j] = false;
                else
                    seg[x][j] = true;
            }

            return;
        }
        lol m = (lx + rx) / 2;
        if (i < m)
        {
            seti(i, v, 2 * x + 1, lx, m);
        }
        else
            seti(i, v, 2 * x + 2, m, rx);

        for (lol j = 0; j < 40; j++)
        {
            if (seg[2 * x + 1][j] || seg[2 * x + 2][j])
                seg[x][j] = true;
            else
                seg[x][j] = false;
        }
    }
    vector<bool> sum(lol l, lol r)
    {
        return sum(l, r, 0, 0, size);
    }
    vector<bool> sum(lol l, lol r, lol x, lol lx, lol rx)
    {
        if (lx >= l && rx <= r)
            return seg[x];
        if (rx <= l || lx >= r)
        {
            vector<bool> y;
            y.assign(40, false);
            return y;
        }
        lol m = (lx + rx) / 2;
        vector<bool> s1 = sum(l, r, 2 * x + 1, lx, m);
        vector<bool> s2 = sum(l, r, 2 * x + 2, m, rx);
        vector<bool> ans;

        for (lol i = 0; i < 40; i++)
        {
            if (s1[i] || s2[i])
                ans.push_back(true);
            else
                ans.push_back(false);
        }
        return ans;
    }
};
lol ans(vector<bool> a)
{
    lol c = 0;
    for (lol i = 0; i < a.size(); i++)
    {
        if (a[i])
            c++;
    }
    return c;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, q;
    cin >> n >> q;
    vector<lol> a;

    for (lol i = 0; i < n; i++)
    {
        lol t;
        cin >> t;
        a.push_back(t);
    }

    SegmentTree s(a);

    while (q--)
    {
        lol c;
        cin >> c;
        if (c == 1)
        {
            lol x, y;
            cin >> x >> y;
            x--;

            cout << ans(s.sum(x, y)) << endl;
        }
        else
        {
            lol x, y;
            cin >> x >> y;
            x--;
            s.seti(x, y);
        }
    }

    return 0;
}