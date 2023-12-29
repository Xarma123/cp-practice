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
        lol n, m;
        cin >> n >> m;
        map<lol, vector<vector<lol>>> mp;
        while (m--)
        {
            lol a, b, c;
            cin >> a >> b >> c;
            mp[a].push_back({b, c});
            mp[b].push_back({a, c});
        }
        lol s[n + 1];
        lol c[n];
        for (lol i = 1; i <= n; i++)
        {
            cin >> s[i];
            c[i - 1] = s[i];
        }
        sort(c, c + n);
        map<pair<lol, lol>, vector<vector<lol>>> mp1;
        for (lol i = 1; i <= n; i++)
        {
            lol j = lower_bound(c, c + n, s[i]) - c;
            j++;
            while (j < n)
            {
                mp1[{i, j}].push_back({i, j - 1, 0});
                j++;
            }
        }
        map<pair<lol, lol>, lol> dis;
        set<pair<lol, pair<lol, lol>>> x;
        lol k = (lower_bound(c, c + n, s[1]) - c);
        x.insert({0, {1, k}});
        while (!x.empty())
        {
            pair<lol, pair<lol, lol>> tp = (*x.begin());
            x.erase(x.begin());
            lol d = tp.first;
            lol a = tp.second.first;
            lol b = tp.second.second;
           
            if (dis.count({a, b}) == 0 || dis[{a, b}] > d)
            {
                dis[{a, b}] = d;
                for (auto e : mp[a])
                {
                    if (dis.count({e[0], b}) == 0 || dis[{e[0], b}] > d + e[1] * 1ll * c[b])
                    {
                        x.insert({d + e[1] * 1ll * c[b], {e[0], b}});
                    }
                }
                for (auto e : mp1[{a, b}])
                {
                    if (dis.count({e[0], e[1]}) == 0 || dis[{e[0], e[1]}] > d + e[2] * 1ll * c[b])
                    {
                        x.insert({d + e[2] * 1ll * c[b], {e[0], e[1]}});
                    }
                }
            }
        }
        lol ans = LONG_LONG_MAX;
        for (lol i = 0; i < n; i++)
        {
            if (dis.count({n, i}))
                ans = min(ans, dis[{n, i}]);
        }
        cout << ans << '\n';
    }

    return 0;
}
