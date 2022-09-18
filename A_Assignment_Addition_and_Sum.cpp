#include <bits/stdc++.h>
#define lol long long
using namespace std;
class segmentTree
{
public:
    vector<vector<pair<lol, lol>>> lazy;
    vector<lol> sum;
    lol size;
    segmentTree(lol n)
    {

        size = 1;
        while (size < n)
            size *= 2;
        lazy.resize(2 * size);
        sum.assign(2 * size, 0ll);
    }
    void propagate(lol x, lol lx, lol rx)
    {
        if (rx - lx == 1)
        {
            lazy[x].clear();
            return;
        }
        lol m = (lx + rx) / 2;
        for (auto run : lazy[x])
        {

            if (run.second == 1)
            {
                sum[2 * x + 1] = run.first * (m - lx);
                sum[2 * x + 2] = run.first * (rx - m);
                lazy[2 * x + 1].clear();
                lazy[2 * x + 2].clear();
                lazy[2 * x + 1].push_back(run);
                lazy[2 * x + 2].push_back(run);
            }
            else
            {
                if (lazy[2 * x + 1].size())
                {
                    if (lazy[2 * x + 1].back().second == 2)
                        lazy[2 * x + 1].back().first += run.first;
                    else
                        lazy[2 * x + 1].push_back(run);
                }
                else
                    lazy[2 * x + 1].push_back(run);
                if (lazy[2 * x + 2].size())
                {
                    if (lazy[2 * x + 2].back().second == 2)
                        lazy[2 * x + 2].back().first += run.first;
                    else
                        lazy[2 * x + 2].push_back(run);
                }
                else
                    lazy[2 * x + 2].push_back(run);
                sum[2 * x + 1] += run.first * (m - lx);
                sum[2 * x + 2] += run.first * (rx - m);
            }
        }
        lazy[x].clear();
    }
    void add1(lol l, lol r, lol v, lol x, lol lx, lol rx)
    {
        propagate(x, lx, rx);
        if (lx >= r || l >= rx)
            return;
        if (lx >= l && rx <= r)
        {
            lazy[x].clear();
            lazy[x].push_back({v, 1});
            sum[x] = v * (rx - lx);
            return;
        }
        lol m = (lx + rx) / 2;
        add1(l, r, v, 2 * x + 1, lx, m);
        add1(l, r, v, 2 * x + 2, m, rx);
        sum[x] = sum[2 * x + 1] + sum[2 * x + 2];
    }

    void add1(lol l, lol r, lol v)
    {
        add1(l, r, v, 0, 0, size);
    }
    void add2(lol l, lol r, lol v, lol x, lol lx, lol rx)
    {

        propagate(x, lx, rx);
        if (lx >= r || l >= rx)
            return;
        if (lx >= l && rx <= r)
        {
            if (lazy[x].size())
            {
                if (lazy[x].back().second == 2)
                    lazy[x].back().first += v;
                else
                    lazy[x].push_back({v, 2});
            }
            else
                lazy[x].push_back({v, 2});
            sum[x] += v * (rx - lx);
            return;
        }
        lol m = (lx + rx) / 2;
        add2(l, r, v, 2 * x + 1, lx, m);
        add2(l, r, v, 2 * x + 2, m, rx);
        sum[x] = (sum[2 * x + 1] + sum[2 * x + 2]);
    }

    void add2(lol l, lol r, lol v)
    {

        add2(l, r, v, 0, 0, size);
    }
    lol sum1(lol l, lol r, lol x, lol lx, lol rx)
    {
        propagate(x, lx, rx);
        if (lx >= r || l >= rx)
            return 0;
        if (lx >= l && rx <= r)
        {
            return sum[x];
        }
        lol m = (lx + rx) / 2;
        lol m1 = sum1(l, r, 2 * x + 1, lx, m);
        lol m2 = sum1(l, r, 2 * x + 2, m, rx);

        lol res = m1 + m2;
        return res;
    }

    lol sum1(lol l, lol r)
    {
        return sum1(l, r, 0, 0, size);
    }
};

int main()
{
    lol n, m;
    cin >> n >> m;

    segmentTree s(n);

    while (m--)
    {
        lol c;
        cin >> c;
        if (c == 1)
        {
            lol l, r, v;
            cin >> l >> r >> v;
            s.add1(l, r, v);
        }
        else if (c == 2)
        {
            lol l, r, v;
            cin >> l >> r >> v;
            s.add2(l, r, v);
        }
        else
        {

            lol l, r;
            cin >> l >> r;
            lol res = s.sum1(l, r);
            cout << res << "\n";
        }
    }
    return 0;
}