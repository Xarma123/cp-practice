#include <bits/stdc++.h>
#define lol long long
using namespace std;
map<lol, vector<lol>> mp;
bool vis[2005];
lol dfs(lol c)
{
    lol v = 1;
    vis[c] = true;
    for (auto e : mp[c])
    {
        if (!vis[e])
        {
            v += dfs(e);
        }
    }
    return v;
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
    lol ans = 0;
    for (lol i = 1; i <= n; i++)
    {
        memset(vis, false, sizeof(vis));
        lol v = dfs(i);
        ans += v - mp[i].size() - 1;
    }
    cout << ans;

    return 0;
}