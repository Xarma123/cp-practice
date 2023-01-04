#include <bits/stdc++.h>
#define lol long long
using namespace std;
class segtree
{
public:
    vector<lol> tree;
    lol n = 1;
    segtree(lol c)
    {
        while (n < c)
            n = n * 2ll;
        tree.assign(2ll * n, 0);
    }
    void set(lol i, lol v, lol x, lol lx, lol rx)
    {
        if (rx - lx == 1)
        {
            tree[x] = v;
            return;
        }
        lol m = (lx + rx) / 2;
        if (i < m)
            set(i, v, 2 * x + 1, lx, m);
        else
            set(i, v, 2 * x + 2, m, rx);
        tree[x] = max(tree[2 * x + 1], tree[2 * x + 2]);
    }
    lol mx(lol l, lol r, lol x, lol lx, lol rx)
    {
        if (lx >= l && rx <= r)
            return tree[x];
        if (lx >= r || rx <= l)
            return 0;
        lol m = (lx + rx) / 2;
        return max(mx(l, r, 2 * x + 1, lx, m), mx(l, r, 2 * x + 2, m, rx));
    }
    void set(lol i, lol v)
    {
        set(i, v, 0, 0, n);
    }
    lol mx(lol l, lol r)
    {
        return mx(l, r, 0, 0, n);
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
       
        lol q;
        map<lol, vector<lol>> mp;
        lol i = 0;
        vector<lol> a;
        while (cin >> q)
        {
            mp[q].push_back(i);
            a.push_back(q);
            i++;    
        }
        lol dp[i];
        segtree s(i);
        memset(dp, 0, sizeof(dp));
        for (auto e : mp)
        {
            for (auto f : e.second)
            {
                dp[f] = s.mx(0, f + 1) + 1;
            }
            for (auto f : e.second)
            {
                s.set(f, dp[f]);
            }
        }
        cout << "Max hits: " << s.mx(0, i) << '\n';
        lol v = s.mx(0, i);
        stack<lol> y;
        for (lol j = i - 1; j >= 0; j--)
        {
            if (dp[j] == v)
            {
                v--;
                y.push(a[j]);
            }
        }
        while (!y.empty())
        {
            cout << y.top() << '\n';
            y.pop();
        }
        if (t)
            cout << '\n';
    }

    return 0;
}