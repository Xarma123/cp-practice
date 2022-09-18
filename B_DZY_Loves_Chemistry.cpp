#include <bits/stdc++.h>
#define lol long long
using namespace std;
bool vis[52];
vector<lol> g[52];
lol d(lol a)
{
    vis[a] = true;
    lol c = 1;
    for (auto e : g[a])
    {
        if (!vis[e])
            c += d(e);
    }
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
    lol ans = 1;
    for (lol i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            lol q = d(i);
            q--;
            ans *= (1ll << q);
        }
    }

    cout << ans;

    return 0;
}