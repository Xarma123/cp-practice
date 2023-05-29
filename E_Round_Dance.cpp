#include <bits/stdc++.h>
using namespace std;
#define lol long long
map<lol, set<lol>> mp;
bool dfs(lol c, lol p, bool vis[])
{
    vis[c] = true;
    bool v = false;
    for (auto e : mp[c])
    {
        if (!vis[e])
        {
            v |= dfs(e, c, vis);
        }
        else if (e != p)
            v = true;
    }
    return v;
}
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[n];
        mp.clear();
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            mp[a[i]].insert(i + 1);
            mp[i + 1].insert(a[i]);
        }
        bool vis[n + 1];
        memset(vis, false, sizeof(vis));
        lol cycle = 0, other = 0;
        for (lol i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                if (dfs(i, -1, vis))
                {
                    cycle++;
                }
                else
                    other++;
            }
        }
        cout << cycle + (other > 0) << " " << cycle + other << "\n";
    }
}