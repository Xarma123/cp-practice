#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    lol dist[n + 1];
    lol dist1[n + 1];
    for (lol i = 0; i <= n; i++)
    {
        dist[i] = LONG_LONG_MAX;
        dist1[i] = LONG_LONG_MAX;
    }
    dist[1] = 0;
    map<lol, vector<pair<lol, lol>>> mp;
    map<lol, vector<pair<lol, lol>>> mp1;
    while (m--)
    {
        lol a, b, c;
        cin >> a >> b >> c;
        mp[a].push_back(make_pair(b, c));
        mp1[b].push_back(make_pair(a, c));
    }

    dist1[n] = 0;
    set<pair<lol, lol>> pq;
    pq.insert(make_pair(0, 1));
    while (!pq.empty())
    {
        pair<lol, lol> x = (*pq.begin());
        pq.erase(x);

        for (lol i = 0; i < mp[x.second].size(); i++)
        {
            if (dist[mp[x.second][i].first] > dist[x.second] + mp[x.second][i].second)
            {
                if (pq.count(make_pair(dist[mp[x.second][i].first], mp[x.second][i].first)))
                    pq.erase(make_pair(dist[mp[x.second][i].first], mp[x.second][i].first));
                dist[mp[x.second][i].first] = dist[x.second] + mp[x.second][i].second;

                pq.insert(make_pair(dist[x.second] + mp[x.second][i].second, mp[x.second][i].first));
            }
        }
    }
    pq.insert({0, n});
    while (!pq.empty())
    {
        pair<lol, lol> x = (*pq.begin());
        pq.erase(x);

        for (lol i = 0; i < mp1[x.second].size(); i++)
        {
            if (dist1[mp1[x.second][i].first] > dist1[x.second] + mp1[x.second][i].second)
            {
                if (pq.count(make_pair(dist1[mp1[x.second][i].first], mp1[x.second][i].first)))
                    pq.erase(make_pair(dist1[mp1[x.second][i].first], mp1[x.second][i].first));
                dist1[mp1[x.second][i].first] = dist1[x.second] + mp1[x.second][i].second;

                pq.insert(make_pair(dist1[x.second] + mp1[x.second][i].second, mp1[x.second][i].first));
            }
        }
    }

    lol ans = LONG_LONG_MAX;
    for (lol i = 1; i <= n; i++)
    {
        for (lol j = 0; j < mp[i].size(); j++)
        {
            if (dist[i] != LONG_LONG_MAX && dist1[mp[i][j].first] != LONG_LONG_MAX)
                ans = min(dist[i] + (mp[i][j].second / 2) + dist1[mp[i][j].first], ans);
        }
    }
    cout << ans;

    return 0;
}