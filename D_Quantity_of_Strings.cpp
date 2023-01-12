#include <bits/stdc++.h>
#define lol long long
using namespace std;
map<lol, vector<lol>> mp;
void dfs(lol c, bool vis[])
{
    vis[c] = true;
    for (auto e : mp[c])
    {
        if (!vis[e])
            dfs(e, vis);
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m, k;
    cin >> n >> m >> k;
    for (lol i = 1; i <= n; i++)
    {
        if (i + k - 1 <= n)
        {
            lol i1 = i, j = i + k - 1;
            while (i1 < j)
            {
                mp[i1].push_back(j);
                mp[j].push_back(i1);
                i1++;
                j--;
            }
        }
    }
    bool vis[n + 1];
    memset(vis, false, sizeof(vis));
    lol ans = 1;
    lol mod = 1e9 + 7;
    for (lol i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            ans = (ans * 1ll * m) % mod;
            dfs(i, vis);
        }
    }
    cout << ans;

    return 0;
}