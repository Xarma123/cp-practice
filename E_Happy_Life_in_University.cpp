#include <bits/stdc++.h>
using namespace std;
#define lol long long

class segtree
{
public:
    vector<lol>
        seg, lazy;
    lol n;
    segtree(lol c)
    {
        n = 1;
        while (n < c)
        {
            n = n * 2ll;
        }
        seg.assign(2ll * n, 0);
        lazy.assign(2ll * n, 0);
    }
    void propagate(lol x, lol lx, lol rx)
    {
        seg[x] += lazy[x];
        if (rx - lx != 1)
        {
            lazy[2ll * x + 1] += lazy[x];
            lazy[2ll * x + 2] += lazy[x];
        }
        lazy[x] = 0;
        return;
    }
    void add(lol l, lol r, lol v, lol x, lol lx, lol rx)
    {
        propagate(x, lx, rx);
        if (lx >= l && rx <= r)
        {
            lazy[x] += v;
            propagate(x, lx, rx);
            return;
        }
        if (lx >= r || rx <= l)
        {
            return;
        }
        lol m = (lx + rx) / 2ll;
        add(l, r, v, 2 * x + 1, lx, m);
        add(l, r, v, 2 * x + 2, m, rx);
        seg[x] = max(seg[2 * x + 1], seg[2 * x + 2]);
    }
    void add(lol l, lol r, lol v)
    {
        add(l, r, v, 0, 0, n);
    }
    lol mx(lol l, lol r, lol x, lol lx, lol rx)
    {
        propagate(x, lx, rx);
        if (lx >= l && rx <= r)
            return seg[x];
        if (lx >= r || rx <= l)
            return LONG_LONG_MIN;
        lol m = (lx + rx) / 2ll;
        return max(mx(l, r, 2 * x + 1, lx, m), mx(l, r, 2 * x + 2, m, rx));
    }
    lol mx(lol l, lol r)
    {
        return mx(l, r, 0, 0, n);
    }
};

vector<lol> mp[300005];
lol a[300005];
lol in[300005];
lol out[300005];
vector<lol> euler;
lol col[300005];

vector<lol> all[300005];
void dfs(lol c)
{
    in[c] = euler.size();
    euler.push_back(c);
    if (col[a[c]] != -1)
        all[col[a[c]]].push_back(c);
    lol temp = col[a[c]];
    col[a[c]] = c;
    for (auto e : mp[c])
    {
        dfs(e);
    }
    col[a[c]] = temp;
    out[c] = euler.size();
}
lol ans = 0;
void dfs(lol c, segtree &s)
{

    for (auto e : mp[c])
    {
        dfs(e, s);
    }

    for (auto e : all[c])
    {
        s.add(in[e], out[e], -1);
    }
    lol mx1 = 0, mx2 = 0;
    for (auto e : mp[c])
    {
        lol v = s.mx(in[e], out[e]);

        if (v >= mx1)
        {
            mx2 = mx1;
            mx1 = v;
        }
        else if (v > mx2)
        {
            mx2 = v;
        }
    }

    ans = max(ans, (mx1 + 1) * 1ll * (mx2 + 1));
    s.add(in[c], out[c], 1);
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

        lol n;
        cin >> n;
        euler.clear();
        for (lol i = 0; i <= n; i++)
        {
            mp[i].clear();
            col[i] = -1;
            all[i].clear();
        }
        ans = 0;

        for (lol i = 2; i <= n; i++)
        {
            lol v;
            cin >> v;
            mp[v].push_back(i);
        }
        for (lol i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        dfs(1);
        segtree s(n);
        dfs(1, s);

        cout << ans << '\n';
    }

    return 0;
}
