#include <bits/stdc++.h>
using namespace std;
#define lol long long
class segmentTree
{
public:
    vector<lol> seg;
    vector<lol> lazy;
    lol size;
    segmentTree(lol n)
    {
        size = 1;
        while (size < n)
            size *= 2;
        seg.assign(2 * size, 0);
        lazy.assign(2 * size, 0);
    }
    void add(lol l, lol r, lol v)
    {
        add(l, r, v, 0, 0, size);
    }
    void add(lol l, lol r, lol v, lol x, lol lx, lol rx)
    {
        if (lazy[x] != 0)
        {
            seg[x] += lazy[x] * (rx - lx);
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
            seg[x] += v * (rx - lx);
            if (rx - lx != 1)
            {
                lazy[2 * x + 1] += v;
                lazy[2 * x + 2] += v;
            }
            return;
        }
        lol m = (lx + rx) / 2;
        add(l, r, v, 2 * x + 1, lx, m);
        add(l, r, v, 2 * x + 2, m, rx);
        seg[x] = seg[2 * x + 1] + seg[2 * x + 2];
    }
    lol sum(lol l, lol r)
    {
        return sum(l, r, 0, 0, size);
    }
    lol sum(lol l, lol r, lol x, lol lx, lol rx)
    {
        if (lazy[x] != 0)
        {
            seg[x] += lazy[x] * (rx - lx);
            if (rx - lx != 1)
            {
                lazy[2 * x + 1] += lazy[x];
                lazy[2 * x + 2] += lazy[x];
            }
            lazy[x] = 0;
        }
        if (lx >= r || rx <= l)
            return 0;
        if (lx >= l && rx <= r)
        {
            return seg[x];
        }
        lol m = (lx + rx) / 2;
        return sum(l, r, 2 * x + 1, lx, m) + sum(l, r, 2 * x + 2, m, rx);
    }
};
vector<lol> tree[600005];
vector<lol> euler;
lol in[600005];
lol out[600005];
void dfs(lol c)
{
    in[c] = euler.size();
    euler.push_back(c);
    for (auto e : tree[c])
    {
        dfs(e);
    }
    out[c] = euler.size();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol q;
        cin >> q;
        for (lol i = 0; i <= q + 1; i++)
        {
            tree[i].clear();
        }
        euler.clear();

        vector<vector<lol>> all;
        lol sz = 2;
        while (q--)
        {
            lol t, v;
            cin >> t >> v;
            if (t == 2)
            {
                lol x;
                cin >> x;
                all.push_back({t, v, x});
            }
            else
            {

                all.push_back({t, v, sz});
                tree[v].push_back(sz);
                sz++;
            }
        }
        dfs(1);
        segmentTree s(euler.size());
        reverse(all.begin(), all.end());
        map<lol, lol> ans;
        for (auto e : all)
        {
            if (e[0] == 1)
            {
                ans[e[2]] = s.sum(in[e[2]], in[e[2]] + 1);
            }
            else
            {
                s.add(in[e[1]], out[e[1]], e[2]);
            }
        }
        ans[1] = s.sum(in[1], in[1] + 1);
        for (auto e : ans)
            cout << e.second << " ";
        cout << '\n';
    }

    return 0;
}
