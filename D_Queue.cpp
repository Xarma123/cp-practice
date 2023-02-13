#include <bits/stdc++.h>
#define lol long long
using namespace std;
class segmentTree
{
public:
    lol n;
    vector<lol> tree;
    segmentTree(lol _n)
    {
        n = 1;
        while (n < _n)
            n = 2ll * n;
        tree.assign(2ll * n, LONG_LONG_MIN);
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
    void set(lol i, lol v)
    {
        set(i, v, 0, 0, n);
    }
    lol mn(lol l, lol r, lol x, lol lx, lol rx)
    {
        if (lx >= l && rx <= r)
            return tree[x];
        if (lx >= r || rx <= l)
            return LONG_LONG_MIN;
        lol m = (lx + rx) / 2;
        return max(mn(l, r, 2 * x + 1, lx, m), mn(l, r, 2 * x + 2, m, rx));
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
    segmentTree s(n);
    pair<lol, lol> a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a + n);
    lol ans[n];
    for (lol i = 0; i < n; i++)
    {
        lol j = i + 1;
        while (j < n && a[j].first == a[i].first)
            j++;
        for (lol k = i; k < j; k++)
        {
            lol v = s.mn(a[k].second, n);
            if (v == LONG_LONG_MIN)
                ans[a[k].second] = -1;
            else
                ans[a[k].second] = v - a[k].second - 1;
        }
        for (lol k = i; k < j; k++)
        {
            s.set(a[k].second, a[k].second);
        }
        i = j - 1;
    }
    for (lol i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}