#include <bits/stdc++.h>
#define lol long long
using namespace std;
map<lol, vector<pair<lol, lol>>> mp;
lol parent[2001];
lol sz[2001];
lol dis[2001];
void dfs(lol c, lol l, lol p)
{
    dis[c] = l;
    for (auto e : mp[c])
    {
        if (e.first != p)
            dfs(e.first, l + e.second, c);
    }
}
lol find(lol a)
{
    if (a == parent[a])
        return a;
    return parent[a] = find(parent[a]);
}
void unio(lol a, lol b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol d[n][n];
    for (lol i = 0; i <= n; i++)
    {
        parent[i] = i;
        sz[i] = 1;
    }

    vector<pair<lol, pair<lol, lol>>> edg;
    for (lol i = 0; i < n; i++)
    {
        for (lol j = 0; j < n; j++)
        {
            lol q;
            cin >> q;
            d[i][j] = q;
            if (i <= j)
                edg.push_back({q, {i, j}});
        }
    }
    sort(edg.begin(), edg.end());
    for (auto e : edg)
    {
        lol c = e.first;
        lol a = e.second.first;
        lol b = e.second.second;
        if (c == 0)
            continue;
        if (find(a) != find(b))
        {
            mp[a].push_back({b, c});
            mp[b].push_back({a, c});
            unio(a, b);
        }
    }
    bool ans = true;
    for (lol i = 1; i < n; i++)
    {
        ans &= (find(i) == find(0));
    }

    for (lol i = 0; i < n; i++)
    {
        dfs(i, 0, -1);
        for (lol j = 0; j < n; j++)
        {
            ans &= (d[i][j] == dis[j]);
        }
    }
    if (ans)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}