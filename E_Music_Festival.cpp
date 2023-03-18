#include <bits/stdc++.h>
#define lol long long
using namespace std;
class segtree
{
public:
    lol n;
    vector<lol> seg;
    segtree(lol c)
    {
        n = 1;
        while (n < c)
            n = n * 2ll;
        seg.assign(2ll * n, 0);
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
        seg[x] = max(seg[2 * x + 1], seg[2 * x + 2]);
    }
    void set(lol i, lol v)
    {
        set(i, v, 0, 0, n);
    }
    lol mx(lol l, lol r, lol x, lol lx, lol rx)
    {
        if (lx >= l && rx <= r)
            return seg[x];
        if (lx >= r || rx <= l)
            return 0;
        lol m = (lx + rx) / 2;
        return max(mx(l, r, 2 * x + 1, lx, m), mx(l, r, 2 * x + 2, m, rx));
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
        lol n;
        cin >> n;
        vector<vector<lol>> albums;
        pair<lol, lol> c[n];
        for (lol i = 0; i < n; i++)
        {
            lol k;
            cin >> k;
            vector<lol> a(k);
            lol mx = 0;
            for (lol j = 0; j < k; j++)
            {
                cin >> a[j];
                mx = max(mx, a[j]);
            }
            albums.push_back(a);
            c[i] = make_pair(mx, i);
        }
        sort(c, c + n);
        segtree dp(c[n - 1].first + 1);
        lol ans = 0;
        for (lol i = 0; i < n; i++)
        {
            stack<lol> x;
            lol v[albums[c[i].second].size()];
            for (lol j = albums[c[i].second].size() - 1; j >= 0; j--)
            {
                while (!x.empty() && x.top() <= albums[c[i].second][j])
                    x.pop();
                x.push(albums[c[i].second][j]);
                v[j] = x.size();
            }
            lol q = dp.mx(c[i].first, c[i].first + 1);
            lol mn = 0;
            for (lol j = 0; j < albums[c[i].second].size(); j++)
            {
                if (albums[c[i].second][j] <= mn)
                    continue;
                mn = albums[c[i].second][j];       
                q = max(q, dp.mx(0, mn) + v[j]);
            }
          
            dp.set(c[i].first, q);
            ans = max(ans, q);
        }
        cout << ans << '\n';
    }

    return 0;
}