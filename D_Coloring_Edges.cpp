#include <bits/stdc++.h>
using namespace std;
#define lol long long
set<pair<lol, lol>> x;
vector<lol> mp[5001];
lol vis[5001];
lol n, m;
void dfs(lol c)
{
    vis[c] = 1;
    for (auto e : mp[c])
    {
        if (vis[e] == 0)
            dfs(e);
        else if (vis[e] == 1)
        {
            x.insert({c, e});
        }
    }
    vis[c] = 2;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    vector<pair<lol, lol>> v;
    for (lol i = 0; i < m; i++)
    {
        lol a, b;
        cin >> a >> b;
        v.push_back({a, b});
        mp[a].push_back(b);
    }
    for (lol i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            dfs(i);
        }
    }

    cout << ((long long)x.size()>0) + 1 << '\n';
    for (lol i = 0; i < m; i++)
    {
        if (x.count(v[i]))
            cout << 2 << " ";
        else
            cout << 1 << ' ';
    }
}