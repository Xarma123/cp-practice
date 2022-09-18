#include <bits/stdc++.h>
#define lol long long
using namespace std;
struct da
{
    lol f[41];
    lol inv;
};

class SegmentTree
{
public:
    lol size;
    vector<da> seg;
    SegmentTree(vector<lol> &a)
    {
        size = 1;
        while (size < a.size())
            size *= 2;
        da x;
        for (lol i = 0; i <= 40; i++)
        {
            x.f[i] = 0;
        }
        x.inv = 0;

        seg.assign(2 * size, x);
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
            da y;
            for (lol j = 0; j <= 40; j++)
            {
                if (j < v)
                    y.f[j] = 0;
                else
                    y.f[j] = 1;
            }
            y.inv = 0;
            seg[x] = y;

            return;
        }
        lol m = (lx + rx) / 2;
        if (i < m)
        {
            set(i, v, 2 * x + 1, lx, m);
        }
        else
            set(i, v, 2 * x + 2, m, rx);
        seg[x].inv = seg[2 * x + 1].inv + seg[2 * x + 2].inv;
        seg[x].f[0] = 0;
        for (lol j = 1; j <= 40; j++)
        {
            seg[x].inv += (seg[2 * x + 2].f[j] - seg[2 * x + 2].f[j - 1]) * (seg[2 * x + 1].f[40] - seg[2 * x + 1].f[j]);
            seg[x].f[j] = seg[2 * x + 1].f[j] + seg[2 * x + 2].f[j];
        }
    }
    da sum(lol l, lol r)
    {
        return sum(l, r, 0, 0, size);
    }
    da sum(lol l, lol r, lol x, lol lx, lol rx)
    {
        if (rx <= l || lx >= r)
        {
            da y;
            for (lol j = 0; j <= 40; j++)
            {

                y.f[j] = 0;
            }
            y.inv = 0;
            return y;
        }
        if (lx >= l && rx <= r)
            return seg[x];
        da s1 = sum(l, r, 2 * x + 1, lx, (lx + rx) / 2);
        da s2 = sum(l, r, 2 * x + 2, (lx + rx) / 2, rx);

        da f;
        f.inv = s1.inv + s2.inv;
        f.f[0] = 0;
        for (lol j = 1; j <= 40; j++)
        {
            f.inv += (s2.f[j] - s2.f[j - 1]) * (s1.f[40] - s1.f[j]);
            f.f[j] = s1.f[j] + s2.f[j];
        }
        return f;
    }
};
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
            cout << s.sum(x, y).inv << '\n';
        }
        else
        {
            lol x, y;
            cin >> x >> y;
            s.set(x - 1, y);
        }
    }

    return 0;
}