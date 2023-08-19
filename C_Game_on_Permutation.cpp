#include <bits/stdc++.h>
using namespace std;
#define lol long long
class SegmentTree
{
public:
    lol size;
    vector<lol> seg;
    SegmentTree(lol n)
    {
        size = 1;
        while (size < n)
            size *= 2;
        seg.assign(2 * size, 0);
    }
    void set(lol i, lol v, lol x, lol lx, lol rx)
    {

        if (rx - lx == 1)
        {
            seg[x] = v;
            return;
        }
        lol m = (lx + rx) / 2;
        if (i < m)
            set(i, v, 2 * x + 1, lx, m);
        else
            set(i, v, 2 * x + 2, m, rx);
        seg[x] = seg[2 * x + 1] + seg[2 * x + 2];
    }
    void set(lol i, lol v)
    {
        set(i, v, 0, 0, size);
    }
    lol sum(lol l, lol r)
    {
        return sum(l, r, 0, 0, size);
    }
    lol sum(lol l, lol r, lol x, lol lx, lol rx)
    {
        if (lx >= r || l >= rx)
            return 0;
        if (lx >= l && rx <= r)
            return seg[x];
        lol m = (lx + rx) / 2;
        return sum(l, r, 2 * x + 1, lx, m) + sum(l, r, 2 * x + 2, m, rx);
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
        lol n;
        cin >> n;
        lol p[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> p[i];
        }
        bool win[n];
        memset(win, false, sizeof(win));
        lol mn = LONG_LONG_MAX;
        for (lol i = 0; i < n; i++)
        {
            if (p[i] < mn)
            {
                mn = p[i];
                win[i] = true;
            }
        }
        map<lol, lol> mp;
        for (lol i = 0; i < n; i++)
        {
            mp[p[i]] = i;
        }
        SegmentTree s(n), c(n);
        lol ans = 0;
        for (lol i = 1; i <= n; i++)
        {
            if (i == 1)
            {
                c.set(mp[i], 1);
                s.set(mp[i], (long long)win[mp[i]]);
            }
            else
            {
                if (c.sum(0, mp[i] + 1) == s.sum(0, mp[i] + 1) && !win[mp[i]])
                {
                    ans++;
                }
                c.set(mp[i], 1);
                s.set(mp[i], (long long)win[mp[i]]);
            }
        }
        cout << ans << '\n';
    }
}