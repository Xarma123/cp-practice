#include <bits/stdc++.h>
#define lol long long
using namespace std;
struct edge
{
    lol a;
    lol b;
    lol c;
};
void dfs(lol s, map<lol, vector<lol>> &mp, bool visited[])
{
    if (visited[s])
        return;
    visited[s] = true;
    for (lol i = 0; i < mp[s].size(); i++)
    {
        dfs(mp[s][i], mp, visited);
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    lol n, m;
    cin >> n >> m;
    vector<edge> x;
    map<lol, vector<lol>> mp;
    map<lol, vector<lol>> mp1;
    lol dist[n + 1];
    bool visited[n + 1];
    bool visited1[n + 1];

    for (lol i = 0; i <= n; i++)
    {
        dist[i] = LONG_LONG_MAX;
        visited1[i] = false;
        visited[i] = false;
    }

    while (m--)
    {
        edge t;
        cin >> t.a >> t.b >> t.c;
        t.c = -t.c;
        x.push_back(t);
        mp[t.a].push_back(t.b);
        mp1[t.b].push_back(t.a);
    }

    dfs(1, mp, visited);
    dfs(n, mp1, visited1);
    bool f = true;
    dist[1] = 0;
    for (lol i = 0; i < n; i++)
    {
        for (lol j = 0; j < x.size(); j++)
        {

            if (dist[x[j].a] != LONG_LONG_MAX && x[j].c != LONG_LONG_MAX)
            {
                if (dist[x[j].b] > dist[x[j].a] + x[j].c)
                {
                    dist[x[j].b] = dist[x[j].a] + x[j].c;
                    if (i == n - 1 && visited1[x[j].b] && visited[x[j].b])
                    {
                        f = false;
                    }
                }
            }
        }
    }
    if (f)
        cout << -dist[n];
    else
        cout << -1;

    return 0;
}