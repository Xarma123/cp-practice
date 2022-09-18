#include <bits/stdc++.h>
using namespace std;
struct node
{
    int u;
    int v;
    int wt;
    node(int first, int second, int weight)
    {
        u = first;
        v = second;
        wt = weight;
    }
};

bool comp(node a, node b)
{
    return a.wt < b.wt;
}

int findPar(int u, vector<int> &parent)
{
    if (u == parent[u])
        return u;
    return parent[u] = findPar(parent[u], parent);
}

void unionn(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findPar(u, parent);
    v = findPar(v, parent);
    if (rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if (rank[v] < rank[u])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}
int main()
{
    int N, m;
    cin >> N >> m;
    vector<node> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back(node(u, v, wt));
    }
    sort(edges.begin(), edges.end(), comp);

    vector<int> parent(N);
    for (int i = 0; i < N; i++)
        parent[i] = i;
    vector<int> rank(N, 0);

    int cost = 0;
    vector<pair<int, int>> mst;
    for (auto it : edges)
    {
        if (findPar(it.v, parent) != findPar(it.u, parent))
        {
            cost += it.wt;
            mst.push_back({it.u, it.v});
            unionn(it.u, it.v, parent, rank);
        }
    }

    int fc = INT_MAX;
    vector<pair<int, int>> bmst2;
    for (int i = 0; i < mst.size(); i++)
    {
        for (int j = 0; j < N; j++)
            parent[j] = j, rank[j] = 0;
        int cost2 = 0;
        vector<pair<int, int>> mst2;

        for (auto it : edges)
        {
            if (findPar(it.v, parent) != findPar(it.u, parent))
            {
                if (it.v == mst[i].first && it.u == mst[i].second)
                    continue;
                if (it.u == mst[i].first && it.v == mst[i].second)
                    continue;

                cost2 += it.wt;
                mst2.push_back({it.u, it.v});
                unionn(it.u, it.v, parent, rank);
            }
        }

        if (cost2 < fc)
        {
            bmst2.clear();
            fc = cost2;
            for (int j = 0; j < mst2.size(); j++)
            {
                bmst2.push_back(mst2[j]);
            }
        }
    }
    cout << fc << endl;
    for (auto it : bmst2)
        cout << it.first << " - " << it.second << endl;

    return 0;
}