#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n, start_a, start_b;
vector<vector<ll>> adjList;
vector<bool> visited;
vector<bool> isCycle;
vector<ll> parent;

void dfs(ll node, ll parentNode)
{
    visited[node] = true;

    for (ll neighbor : adjList[node])
    {
        if (!visited[neighbor])
        {
            parent[node] = neighbor;
            dfs(neighbor, node);
            parent[node] = -1;
        }
        else if (neighbor != parentNode)
        {
            isCycle[node] = true;
            ll v = neighbor;
            while (v != -1)
            {
                isCycle[v] = true;
                v = parent[v];
            }
        }
    }
}

void bfs(ll start, vector<ll> &dist)
{
    queue<ll> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty())
    {
        ll node = q.front();
        q.pop();

        for (ll neighbor : adjList[node])
        {
            if (dist[neighbor] == -1)
            {
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;

    while (t--)
    {
        cin >> n >> start_a >> start_b;
        adjList.clear();
        visited.clear();
        isCycle.clear();
        parent.clear();
        adjList.assign(n + 1, vector<ll>());
        visited.assign(n + 1, false);
        isCycle.assign(n + 1, false);
        parent.assign(n + 1, -1);

        for (ll i = 0; i < n; i++)
        {
            ll u, v;
            cin >> u >> v;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        dfs(1, -1);

        bool noCycle = true;
        for (ll i = 1; i <= n; i++)
        {
            if (isCycle[i])
            {
                noCycle = false;
                break;
            }
        }

        if (noCycle)
        {
            cout << "NO\n";
            continue;
        }

        vector<ll> distA(n + 1, -1);
        vector<ll> distB(n + 1, -1);

        bfs(start_a, distA);
        bfs(start_b, distB);

        bool answer = false;
        for (ll i = 1; i <= n; i++)
        {
            if (isCycle[i])
            {
                if (distA[i] > distB[i])
                {
                    answer = true;
                    break;
                }
            }
        }

        if (answer)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
