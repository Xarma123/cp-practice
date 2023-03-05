#include <bits/stdc++.h>
#define lol long long
using namespace std;
map<lol, vector<lol>> mp;
bool vis[200005];
lol nodes, edges;
void dfs(lol c)
{
    nodes++;
    vis[c] = true;
    for (auto e : mp[c])
    {
        if (!vis[e])
            dfs(e);
    }
    edges += mp[c].size();
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    while (m--)
    {
        lol a, b;
        cin >> a >> b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    bool ans = true;
    for (lol i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            nodes = 0;
            edges = 0;
            dfs(i);
            if (nodes != (edges / 2))
                ans = false;
        }
    }
    if (ans)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}