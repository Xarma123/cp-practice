#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m, k;
    cin >> n >> m >> k;
    vector<lol> dist[n + 1];
    for (lol i = 0; i <= n; i++)
    {
        for (lol j = 0; j < k; j++)
        {
 
            dist[i].push_back(LONG_LONG_MAX);
        }
    }
    dist[1][0] = 0;
 
    map<lol, vector<pair<lol, lol>>> mp;
    while (m--)
    {
        lol a, b, c;
        cin >> a >> b >> c;
        mp[a].push_back(make_pair(b, c));
    }
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>>
        pq;
    pq.push(make_pair(0, 1));
    while (!pq.empty())
    {
 
        lol u = pq.top().second;
        lol d = pq.top().first;
        pq.pop();
        if (dist[u][k - 1] < d)
            continue;
 
        for (auto e : mp[u])
        {
            lol v = e.first;
            lol c = e.second;
 
            if (dist[v][k - 1] > c * 1ll + d * 1ll)
            {
                dist[v][k - 1] = c * 1ll + d * 1ll;
                pq.push({dist[v][k - 1], v});
                sort(dist[v].begin(), dist[v].end());
            }
        }
    }
    for (lol i = 0; i < k; i++)
    {
        cout << dist[n][i] << " ";
    }
 
    return 0;
}