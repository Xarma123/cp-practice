#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
const int N = 9e3 + 10;
vector<pair<pair<lli, lli>, lli>> graph;
lli n, m;
lli par[N];
void bellman_ford()
{
    vector<lli> distance(N, INT_MAX);
    distance[1] = 0;
    for (lli i = 1; i <= n - 1; i++)
    {
        for (lli j = 0; j < m; j++)
        {
            lli u = graph[j].first.first;
            lli v = graph[j].first.second;
            lli weight = graph[j].second;
            if (distance[u] + weight < distance[v])
            {

                par[v] = u;
                distance[v] = distance[u] + weight;
            }
        }
    }
    lli node = -1;
    for (lli i = 0; i < m; i++)
    {
        lli u = graph[i].first.first;
        lli v = graph[i].first.second;
        lli weight = graph[i].second;
        if (distance[u] + weight < distance[v])
        {

            par[v] = u;
            node = v;
            break;
        }
    }

    if (node != -1)
        cout << "YES" << endl;
    else
    {
        cout << "NO";
        return;
    }
    for (lli i = 0; i < n; i++)
    {
        node = par[node];
    }
    lli temp = node;
    vector<lli> val;
    cout << node << " ";
    node = par[node];
    while (node != temp)
    {
        if (node == 0)
            break;
        val.push_back(node);
        node = par[node];
    }
    reverse(val.begin(), val.end());
    for (auto &i : val)
        cout << i << " ";
    cout << temp;
}
int main()
{
    cin >> n >> m;
    for (lli i = 0; i < m; i++)
    {
        int a, b;
        lli c;
        cin >> a >> b >> c;
        graph.push_back({{a, b}, c});
    }
    bellman_ford();
}