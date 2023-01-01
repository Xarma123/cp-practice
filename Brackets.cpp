#include <bits/stdc++.h>
#define lol long long
using namespace std;
class segTree
{
public:
    vector<lol> seg, lazy;
    lol n;
    segTree(lol c)
    {
        n = 1;
        while (n < c)
            n = n * 2ll;
        seg.assign(2ll * n, LONG_LONG_MAX);
        lazy.assign(2ll * n, 0ll);
    }
    void propagate(lol x, lol lx, lol rx)
    {
        seg[x] += lazy[x];
        if (rx - lx != 1)
        {
            lazy[2 * x + 1] += lazy[x];
            lazy[2 * x + 2] += lazy[x];
        }
        lazy[x] = 0;
    }
    void set(lol i, lol v, lol x, lol lx, lol rx)
    {
        propagate(x, lx, rx);
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
        seg[x] = min(seg[2 * x + 1], seg[2 * x + 2]);
    }
    void set(lol i, lol v)
    {
        set(i, v, 0, 0, n);
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
        lol m = (lx + rx) / 2;
        add(l, r, v, 2 * x + 1, lx, m);
        add(l, r, v, 2 * x + 2, m, rx);
        seg[x] = min(seg[2 * x + 1], seg[2 * x + 2]);
    }
    void add(lol l, lol r, lol v)
    {
        add(l, r, v, 0, 0, n);
    }
    lol mn(lol l, lol r, lol x, lol lx, lol rx)
    {
        propagate(x, lx, rx);
        if (lx >= l && rx <= r)
        {
            return seg[x];
        }
        if (lx >= r || rx <= l)
        {
            return LONG_LONG_MAX;
        }
        lol m = (lx + rx) / 2;
        return min(mn(l, r, 2 * x + 1, lx, m), mn(l, r, 2 * x + 2, m, rx));
    }
    lol mn(lol l, lol r)
    {
        return mn(l, r, 0, 0, n);
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol cs = 1;
    lol n;
    while (cin >> n)
    {
        cout << "Test " << cs << ":" << endl;
        string a;
        cin >> a;
        segTree s(n);
        lol c = 0;
        for (lol i = 0; i < n; i++)
        {
            if (a[i] == '(')
                c++;
            else
                c--;
            s.set(i, c);
        }

        lol m;
        cin >> m;
        while (m--)
        {
            lol k;
            cin >> k;
            if (k == 0)
            {
                if (s.mn(0, n) == 0 && s.mn(n - 1, n) == 0)
                {
                    cout << "YES" << '\n';
                }
                else
                    cout << "NO" << '\n';
            }
            else
            {
                if (a[k - 1] == '(')
                {
                    a[k - 1] = ')';
                    s.add(k - 1, n, -2);
                }
                else
                {
                    a[k - 1] = '(';
                    s.add(k - 1, n, 2);
                }
            }
        }
        cs++;
    }

    return 0;
}