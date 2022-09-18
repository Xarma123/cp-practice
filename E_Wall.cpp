#include <bits/stdc++.h>
#define lol long long
using namespace std;
class segmentTree
{
public:
    lol size;
    vector<pair<lol, lol>> lazy;
    vector<lol> mn;
    segmentTree(lol n)
    {
        size = 1;
        while (size < n)
            n *= 2;
        lazy.assign(2 * size, {LONG_LONG_MAX, -1});
        mn.assign(2 * size, 0);
    }
    void propagate(lol x, lol lx, lol rx)
    {
        if (lazy[x].first == LONG_LONG_MAX || rx - lx == 1)
        {
            lazy[x] = {LONG_LONG_MAX, -1};
            return;
        }
        lol m = (lx + rx) / 2;
        if (lazy[x].second == 1)
        {
            mn[2 * x + 1] = min(mn[2 * x + 1], lazy[x].first);
            lazy[2 * x + 1] = lazy[x];
            mn[2 * x + 2] = min(mn[2 * x + 2], lazy[x].first);
            lazy[2 * x + 2] = lazy[x];
        }
        else
        {
            mn[2 * x + 1] = max(mn[2 * x + 1], lazy[x].first);
            lazy[2 * x + 1] = lazy[x];
            mn[2 * x + 2] = max(mn[2 * x + 2], lazy[x].first);
            lazy[2 * x + 2] = lazy[x];
        }

        lazy[x] = {LONG_LONG_MAX, -1};
    }
    void add(lol l, lol r, lol h)
    {
        add(l, r, h, 0, 0, size);
    }
    void add(lol l, lol r, lol h, lol x, lol lx, lol rx)
    {
        propagate(x, lx, rx);
        if (lx >= r || rx <= l)
            return;
        if (lx >= l && rx <= r)
        {
            mn[x] = max(mn[x], h);
            lazy[x] = {h, 0};
            return;
        }

        lol m = (lx + rx) / 2;
        add(l, r, h, 2 * x + 1, lx, m);
        add(l, r, h, 2 * x + 2, m, rx);
        mn[x] = min(mn[2 * x + 1], mn[2 * x + 2]);
    }
    void addn(lol l, lol r, lol h)
    {
        addn(l, r, h, 0, 0, size);
    }
    void addn(lol l, lol r, lol h, lol x, lol lx, lol rx)
    {
        propagate(x, lx, rx);
        if (lx >= r || rx <= l)
            return;
        if (lx >= l && rx <= r)
        {
            mn[x] = min(mn[x], h);
            lazy[x] = {h, 1};
            return;
        }

        lol m = (lx + rx) / 2;
        add(l, r, h, 2 * x + 1, lx, m);
        add(l, r, h, 2 * x + 2, m, rx);
        mn[x] = min(mn[2 * x + 1], mn[2 * x + 2]);
    }
    lol get(lol i)
    {
        get(i, i + 1, 0, 0, size);
    }
    lol get(lol l, lol r, lol x, lol lx, lol rx)
    {
        propagate(x, lx, rx);
        if (lx >= r || rx <= l)
            return LONG_LONG_MAX;
        if (lx >= l && rx <= r)
        {
            return mn[x];
            
        }
        lol m = (lx + rx) / 2;
        return min(get(l, r, 2 * x + 1, lx, m), get(l, r, 2 * x + 2, m, rx));
    }
};
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, k;
    cin >> n >> k;
    segmentTree s(n);
    while (k--)
    {
        lol c;
        cin >> c;
        lol l, r, h;
        cin >> l >> r >> h;
        if (c == 1)
        {
            r++;
            s.add(l, r, h);
        }
        else
        {
            r++;
            s.addn(l, r, h);
        }
    }

    for (lol i = 0; i < n; i++)
    {
        cout << s.get(i) << "\n";
    }

    return 0;
}