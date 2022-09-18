#include <bits/stdc++.h>
#define lol long long
using namespace std;
map<lol, vector<lol>> mp;
vector<lol> topo;
vector<bool> vis;
vector<lol> dis;

void dfs(lol c)
{
    vis[c] = true;
    for (auto e : mp[c])
    {
        if (!vis[e])
            dfs(e);
    }
    topo.push_back(c);
}
void dfs1(lol c)
{

    dis[c] = 0;
    lol mx = LONG_LONG_MIN;
    for (auto e : mp[c])
    {
        if (dis[e] == LONG_LONG_MIN)
        {
            dfs1(e);
        }
        mx = max(mx, dis[e]);
    }
    if (mx != LONG_LONG_MIN)
        dis[c] += mx + 1;
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
    }
    vis.assign(n + 1, false);
    for (lol i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs(i);
    }
    reverse(topo.begin(), topo.end());
    dis.assign(n + 1, LONG_LONG_MIN);

    for (auto i : topo)
    {
        if (dis[i] == LONG_LONG_MIN)
            dfs1(i);
    }
    lol mx = LONG_LONG_MIN;
    for (lol i = 0; i <= n; i++)
    {
        mx = max(mx, dis[i]);
    }
    cout << mx;
    return 0;
}