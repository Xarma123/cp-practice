#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, m, k;
        cin >> n >> m >> k;
        pair<lol, lol> a[m];
        for (lol i = 0; i < m; i++)
        {
            cin >> a[i].first >> a[i].second;
            a[i].first--;
            a[i].second--;
        }
        sort(a, a + m);
        lol c[n];
        memset(c, 0, sizeof(c));
        set<pair<lol, lol>> x;
        lol j = 0;
        vector<pair<lol, lol>> v;
        for (lol i = 0; i < n; i++)
        {
            while (j < m && a[j].first <= i)
            {
                x.insert({a[j].second, j});
                j++;
            }
            while (!x.empty() && (*x.begin()).first < i)
                x.erase(x.begin());
            c[i] = x.size();
            if (x.size() == 2)
            {
                auto it = x.begin();
                v.push_back({(*it).second, (*(++it)).second});
            }
        }
        lol cone[n], ctwo[n];
        memset(cone, 0, sizeof(cone));
        memset(ctwo, 0, sizeof(ctwo));
        lol ex = 0;
        for (lol i = 0; i < n; i++)
        {
            cone[i] = (c[i] == 1ll);
            ctwo[i] = (c[i] == 2ll);
            ex += (c[i] == 0ll);
        }
        for (lol i = 1; i < n; i++)
        {
            cone[i] += cone[i - 1];
            ctwo[i] += ctwo[i - 1];
        }
        lol ans = 0;
        for (auto e : v)
        {
            lol l1 = a[e.first].first;
            lol r1 = a[e.first].second;
            lol l2 = a[e.second].first;
            lol r2 = a[e.second].second;
            lol l3 = max(l1, l2);
            lol r3 = min(r1, r2);
            lol v = ctwo[r3];
            if (l3 - 1 >= 0)
                v -= ctwo[l3 - 1];
            v += cone[r1];
            if (l1 - 1 >= 0)
                v -= cone[l1 - 1];
            v += cone[r2];
            if (l2 - 1 >= 0)
                v -= cone[l2 - 1];
            ans = max(ans, v + ex);
        }
        lol mx1 = 0, mx2 = 0;
        for (lol i = 0; i < m; i++)
        {
            lol l = a[i].first;
            lol r = a[i].second;
            lol v = cone[r];
            if (l - 1 >= 0)
                v -= cone[l - 1];
            if (mx1 <= v)
            {
                mx2 = mx1;
                mx1 = v;
            }
            else if (mx2 < v)
                mx2 = v;
        }
        ans = max(ans, mx1 + mx2+ex);
        cout << ans << '\n';
    }

    return 0;
}
