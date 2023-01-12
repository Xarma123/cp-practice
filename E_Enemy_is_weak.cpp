#include <bits/stdc++.h>
#define lol long long
using namespace std;
class segtree
{
public:
    vector<vector<lol>> tree;
    lol n = 1;
    segtree(lol c)
    {
        while (n < c)
            n = n * 2ll;
        tree.resize(2ll * n);
    }
    void set(lol i, lol v, lol x, lol lx, lol rx)
    {
        if (rx - lx == 1)
        {
            tree[x].clear();
            tree[x].push_back(v);
            return;
        }
        lol m = (lx + rx) / 2;
        if (i < m)
            set(i, v, 2 * x + 1, lx, m);
        else
            set(i, v, 2 * x + 2, m, rx);
        tree[x].clear();
        lol i1 = 0, i2 = 0;
        lol l = 2 * x + 1;
        lol r = l + 1;
        while (i1 < tree[l].size() && i2 < tree[r].size())
        {
            if (tree[l][i1] <= tree[r][i2])
            {
                tree[x].push_back(tree[l][i1]);
                i1++;
            }
            else
            {
                tree[x].push_back(tree[r][i2]);
                i2++;
            }
        }
        while (i1 < tree[l].size())
        {
            tree[x].push_back(tree[l][i1]);
            i1++;
        }
        while (i2 < tree[r].size())
        {
            tree[x].push_back(tree[r][i2]);
            i2++;
        }
        
        
      
    }
    void set(lol i, lol v)
    {
        set(i, v, 0, 0, n);
    }
    lol mn(lol l, lol r, lol v, lol x, lol lx, lol rx)
    {
        if (lx >= l && rx <= r)
        {
            lol i = lower_bound(tree[x].begin(), tree[x].end(), v) - tree[x].begin();
            return i;
        }
        if (lx >= r || rx <= l)
            return 0;
        lol m = (lx + rx) / 2;
        return mn(l, r, v, 2 * x + 1, lx, m) + mn(l, r, v, 2 * x + 2, m, rx);
    }
    lol mn(lol l, lol r, lol v)
    {
        return mn(l, r, v, 0, 0, n);
    }
    lol mx(lol l, lol r, lol v, lol x, lol lx, lol rx)
    {
        if (lx >= l && rx <= r)
        {
            lol i = upper_bound(tree[x].begin(), tree[x].end(), v) - tree[x].begin();
            return tree[x].size() - i;
        }
        if (lx >= r || rx <= l)
            return 0;
        lol m = (lx + rx) / 2;
        return mx(l, r, v, 2 * x + 1, lx, m) + mx(l, r, v, 2 * x + 2, m, rx);
    }
    lol mx(lol l, lol r, lol v)
    {
        return mx(l, r, v, 0, 0, n);
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    segtree s(n);
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        s.set(i, a[i]);
    }
    lol ans = 0;
    for (lol i = 0; i < n; i++)
    {
        ans += s.mx(0, i, a[i]) * 1ll * s.mn(i + 1, n, a[i]);
    }
    cout << ans;

    return 0;
}