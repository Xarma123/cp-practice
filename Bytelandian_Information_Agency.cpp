#include <bits/stdc++.h>
#define lol long long
using namespace std;
vector<lol> mp[200005];
void dfs(lol c, bool vis[], lol j)
{
    vis[c] = true;
    for (auto e : mp[c])
    {
        if (!vis[e] && e != j)
            dfs(e, vis, j);
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol c = 10;
    while (c--)
    {
        lol n, m;
        cin >> n >> m;
        for (lol i = 0; i <= n; i++)
        {
            mp[i].clear();
        }
        while (m--)
        {
            lol a, b;
            cin >> a >> b;
            mp[a].push_back(b);
        }
        bool vis[n + 1];
        memset(vis, false, sizeof(vis));
        vector<lol> ans;
        ans.push_back(1);
        for (lol i = 2; i <= n; i++)
        {
            dfs(1, vis, i);
            bool q = true;
            for (lol j = 1; j <= n; j++)
            {
                if (j != i)
                    q &= vis[j];
                vis[j] = false;
            }
            if (!q)
                ans.push_back(i);
        }
        cout << ans.size() << '\n';
        for (auto e : ans)
            cout << e << " ";
        cout << '\n';
    }

    return 0;
}