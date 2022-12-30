#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol MIN = LONG_LONG_MAX;
class segTree
{
public:
    vector<lol> tree, lazy;
    lol n = 1;
    segTree(lol c)
    {
        while (n < c)
            n = n * 2ll;
        tree.assign(2ll * n, MIN);
        lazy.assign(2ll * n, 0);
    }
    void propagate(lol x, lol lx, lol rx)
    {
        tree[x] += lazy[x];
        if (rx - lx != 1)
        {
            lazy[2 * x + 1] += lazy[x];
            lazy[2 * x + 2] += lazy[x];
        }
        lazy[x] = 0;
    }
    void set(lol l, lol r, lol v, lol x, lol lx, lol rx)
    {
        propagate(x, lx, rx);
        if (lx >= l && rx <= r)
        {
            lazy[x] += v;
            propagate(x, lx, rx);
            return;
        }
        if (lx >= r || rx <= l)
            return;
        lol m = (lx + rx) / 2;
        set(l, r, v, 2 * x + 1, lx, m);
        set(l, r, v, 2 * x + 2, m, rx);
        tree[x] = min(tree[2 * x + 1], tree[2 * x + 2]);
    }
    void set(lol l, lol r, lol v)
    {
        set(l, r, v, 0, 0, n);
    }
    lol mn(lol l, lol r, lol x, lol lx, lol rx)
    {
        propagate(x, lx, rx);
        if (lx >= l && rx <= r)
            return tree[x];
        if (lx >= r || rx <= l)
            return MIN;
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
    lol n;
    cin >> n;
    lol a[n];
    segTree seg(n);
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        seg.set(i, i + 1, a[i] - MIN);
    }
    lol m;
    cin >> m;
    cin.ignore();
    while (m--)
    {
        string s;
        getline(cin, s);
        stringstream q(s);
        vector<lol> v;
        while (q >> s)
        {
            lol x = stoll(s);
            v.push_back(x);
        }

        if (v.size() == 2)
        {
            if (v[0] <= v[1])
            {
                cout << seg.mn(v[0], v[1] + 1) << endl;
            }
            else
            {
                lol x = seg.mn(v[0], n);
                x = min(x, seg.mn(0, v[1] + 1));
                cout << x << endl;
            }
        }
        else
        {
            if (v[0] <= v[1])
            {
                seg.set(v[0], v[1] + 1, v[2]);
            }
            else
            {
                seg.set(v[0], n, v[2]);
                seg.set(0, v[1] + 1, v[2]);
            }
        }
    }

    return 0;
}