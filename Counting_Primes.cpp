#include <bits/stdc++.h>
#include <stdio.h>
#define lol int
using namespace std;
class segTree
{
public:
    vector<lol> tree, lazy;
    lol n;
    segTree(lol c)
    {
        n = 1;
        while (n < c)
            n *= 2ll;
        tree.assign(2ll * n, 0);
        lazy.assign(2ll * n, -1);
    }
    void propagate(lol x, lol lx, lol rx)
    {
        if (lazy[x] != -1)
        {
            tree[x] = lazy[x] * 1ll * (rx - lx);

            if (rx - lx != 1)
            {
                lazy[2 * x + 1] = lazy[x];
                lazy[2 * x + 2] = lazy[x];
            }
        }
        lazy[x] = -1;
    }
    void set(lol l, lol r, lol v, lol x, lol lx, lol rx)
    {
        propagate(x, lx, rx);
        if (lx >= l && rx <= r)
        {
            lazy[x] = v;
            propagate(x, lx, rx);
            return;
        }
        if (lx >= r || rx <= l)
        {
            return;
        }
        lol m = (lx + rx) / 2;
        set(l, r, v, 2 * x + 1, lx, m);
        set(l, r, v, 2 * x + 2, m, rx);
        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }
    void set(lol l, lol r, lol v)
    {
        set(l, r, v, 0, 0, n);
    }
    lol sum(lol l, lol r, lol x, lol lx, lol rx)
    {
        propagate(x, lx, rx);
        if (lx >= l && rx <= r)
        {
            return tree[x];
        }
        if (lx >= r || rx <= l)
            return 0;
        lol m = (lx + rx) / 2;
        return sum(l, r, 2 * x + 1, lx, m) + sum(l, r, 2 * x + 2, m, rx);
    }
    lol sum(lol l, lol r)
    {
        return sum(l, r, 0, 0, n);
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    bitset<100001> p;
    p.set();
    p[0] = 0;
    p[1] = 0;
    for (lol i = 2; i * i < 100001; i++)
    {
        if (p[i])
        {
            for (lol j = i * i; j < 100001; j += i)
            {
                p[j] = 0;
            }
        }
    }

    lol t;
    scanf("%d", &t);
    lol cas = 1;
    while (t--)
    {
        printf("Case %d:\n", cas++);
        lol n, q;
        scanf("%d %d", &n, &q);
        segTree s(n);
        for (lol i = 0; i < n; i++)
        {
            lol v;
            scanf("%d", &v);
            s.set(i, i + 1, (long long)p[v]);
        }

        while (q--)
        {
            lol c;
            cin >> c;
            if (c == 0)
            {
                lol l, r, v;
                scanf("%d %d %d", &l, &r, &v);

                l--;
                s.set(l, r, (long long)p[v]);
            }
            else
            {
                lol l, r;
                scanf("%d %d", &l, &r);
                l--;
                printf("%d\n", s.sum(l, r));
            }
        }
    }

    return 0;
}