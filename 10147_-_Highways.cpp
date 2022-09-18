#include <bits/stdc++.h>
#define lol long long
using namespace std;
vector<pair<lol, long double>> g[1000];
long double cal(pair<lol, lol> a, pair<lol, lol> b)
{
    return sqrtl((a.first - b.first) * 1ll * (a.first - b.first) + (a.second - b.second) * 1ll * (a.second - b.second));
}
lol parent[1000], sz[1000];
lol find(lol a)
{
    if (parent[a] == -1)
        return a;
    return parent[a] = find(parent[a]);
}
void unio(lol a, lol b)
{
    lol ap = find(a);
    lol bp = find(b);
    if (ap == bp)
        return;
    if (sz[ap] <= sz[bp])
    {
        parent[ap] = bp;
        sz[bp] += sz[ap];
    }
    else
    {
        parent[bp] = ap;
        sz[ap] += sz[bp];
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        for (lol i = 0; i < 1000; i++)
        {
            g[i].clear();
        }

        lol n;
        cin >> n;
        vector<pair<lol, lol>> p;
        for (lol i = 0; i < n; i++)
        {
            lol a, b;
            cin >> a >> b;
            p.push_back({a, b});
        }
        lol m;
        cin >> m;
        memset(parent, -1, sizeof(parent));
        memset(sz, 1, sizeof(sz));
        while (m--)
        {
            lol a, b;
            cin >> a >> b;
            unio(a, b);
        }
        for (lol i = 0; i < p.size(); i++)
        {
            for (lol j = i + 1; j < p.size(); j++)
            {
                long double v = cal(p[i], p[j]);
                g[i + 1].push_back({j + 1, v});
                g[j + 1].push_back({i + 1, v});
            }
        }

        vector<pair<long double, pair<lol, lol>>> edge;
        for (lol i = 1; i <= n; i++)
        {
            for (auto e : g[i])
            {
                edge.push_back({e.second, {i, e.first}});
            }
        }
        sort(edge.begin(), edge.end());
        vector<pair<lol, lol>> ans;
        for (lol i = 0; i < edge.size(); i++)
        {
            long double c = edge[i].first;
            lol a = edge[i].second.first;
            lol b = edge[i].second.second;
            if (find(a) != find(b))
            {

                unio(a, b);
                ans.push_back({a, b});
            }
        }
        if (ans.size() == 0)
            cout << "No new highways need" << endl;
        else
        {
            for (auto e : ans)
            {
                cout << e.first << " " << e.second << endl;
            }
        }
        if (t)
            cout << endl;
    }

    return 0;
}