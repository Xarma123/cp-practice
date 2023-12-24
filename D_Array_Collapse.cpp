#include <bits/stdc++.h>
using namespace std;
#define lol long long
lol mod = 998244353;
class segtree
{
public:
    vector<lol> tree;
    lol n;
    segtree(lol c)
    {
        n = 1;
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
        lol m = (lx + rx) / 2ll;
        if (i < m)
        {
            set(i, v, 2 * x + 1, lx, m);
        }
        else
            set(i, v, 2 * x + 2, m, rx);
        tree[x] = (tree[2 * x + 1] + tree[2 * x + 2]) % mod;
    }
    void set(lol i, lol v)
    {
        set(i, v, 0, 0, n);
    }
    lol sum(lol l, lol r, lol x, lol lx, lol rx)
    {
        if (lx >= l && rx <= r)
            return tree[x];
        if (lx >= r || rx <= l)
            return 0;
        lol m = (lx + rx) / 2ll;
        return (sum(l, r, 2 * x + 1, lx, m) + sum(l, r, 2 * x + 2, m, rx)) % mod;
    }
    lol sum(lol l, lol r)
    {
        return sum(l, r, 0, 0, n);
    }
};
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
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol ps[n];
        lol ns[n];
        stack<lol> x;
        x.push(-1);
        for (lol i = 0; i < n; i++)
        {
            while (x.top() != -1 && a[x.top()] > a[i])
            {
                ns[x.top()] = i;
                x.pop();
            }
            ps[i] = x.top();
            x.push(i);
        }
        while (x.top() != -1)
        {
            ns[x.top()] = -1;
            x.pop();
        }

        lol p[n];
        segtree s(n);
        lol ans = 0;
        lol c[n];
        memset(c, 0, sizeof(c));
        for (lol i = 0; i < n; i++)
        {
            if (i == 0)
            {
                p[i] = 1;
            }
            else
            {
                p[i] = s.sum(ps[i] + 1, i);
                if (ps[i] == -1)
                    p[i]++;
                p[i] %= mod;
                if (ps[i] != -1)
                {
                    p[i] += c[ps[i]];
                    p[i] %= mod;
                }
            }
            if (ns[i] == -1)
            {
                ans += p[i];
                ans %= mod;
            }
            c[i] = p[i];
            if (ps[i] != -1)
            {
                c[i] += c[ps[i]];
                c[i] %= mod;
            }

            s.set(i, p[i]);
        }

        cout << ans << '\n';
    }

    return 0;
}
