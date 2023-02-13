#include <bits/stdc++.h>
#define lol long long
using namespace std;
map<lol, vector<pair<lol, lol>>> g;
map<lol, vector<pair<lol, lol>>> gr;
vector<vector<lol>> edg;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t1;
    cin >> t1;
    while (t1--)
    {
        g.clear();
        gr.clear();
        edg.clear();
        lol n, m, s, t, p;
        cin >> n >> m >> s >> t >> p;
        while (m--)
        {
            lol u, v, c;
            cin >> u >> v >> c;
            edg.push_back({u, v, c});
            g[u].push_back({v, c});
            gr[v].push_back({u, c});
        }
        lol d[n + 1];
        lol d1[n + 1];
        for (lol i = 0; i <= n; i++)
        {
            d[i] = LONG_LONG_MAX;
            d1[i] = LONG_LONG_MAX;
        }

        set<pair<lol, lol>> x;
        x.insert({0, s});
        while (!x.empty())
        {
            pair<lol, lol> v = (*x.begin());
            x.erase(x.begin());
            if (v.first > d[v.second])
                continue;
            d[v.second] = v.first;
            for (auto e : g[v.second])
            {
                if (d[e.first] > e.second + d[v.second])
                    x.insert({e.second + d[v.second], e.first});
            }
        }
        x.insert({0, t});
        while (!x.empty())
        {
            pair<lol, lol> v = (*x.begin());
            x.erase(x.begin());
            if (v.first > d1[v.second])
                continue;
            d1[v.second] = v.first;
            for (auto e : gr[v.second])
            {
                if (d1[e.first] > e.second + d1[v.second])
                    x.insert({e.second + d1[v.second], e.first});
            }
        }
        lol ans = -1;
        for (auto e : edg)
        {
            lol a = e[0], b = e[1], c = e[2];
            if (d[a] != LONG_LONG_MAX && d1[b] != LONG_LONG_MAX)
            {
                if (d[a] + d1[b] + c <= p)
                    ans = max(ans, c);
            }
        }
        cout << ans << '\n';
    }

    return 0;
}