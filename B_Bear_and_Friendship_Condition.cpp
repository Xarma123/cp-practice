#include <bits/stdc++.h>
#define lol long long
using namespace std;
vector<lol> g[200000];
bool vis[200000];
vector<lol> x;
lol dfs(lol a)
{
    x.push_back(a);
    lol c = 1;
    vis[a] = true;
    for (auto e : g[a])
        if (!vis[e])
            c += dfs(e);
    return c;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    memset(vis, false, sizeof(vis));
    while (m--)
    {
        lol a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    bool ans = true;
    for (lol i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            x.clear();
            lol c = dfs(i);
            for (auto e : x)
            {
                if (g[e].size() != c - 1)
                {
                    ans = false;
                }
            }
        }
    }
    if (ans)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}