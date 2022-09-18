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
    for (lol i = 0; i <= n; i++)
    {
        dist[i] = LONG_LONG_MAX;
    }

    dist[1] = 0;
    map<lol, vector<pair<lol, lol>>> mp;
    while (m--)
    {
        lol a, b, c;
        cin >> a >> b >> c;
        mp[a].push_back(make_pair(b, c));
    }
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

                pq.insert(make_pair(dist[mp[x.second][i].first], mp[x.second][i].first));
            }
        }
    }
    for (lol i = 1; i <= n; i++)
    {
        cout << dist[i] << " ";
    }

    return 0;
}