#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol s, d;
lol dfs(lol p, map<lol, vector<lol>> &mp, bool visited[], lol parent[])
{
    visited[p] = true;
    for (lol i = 0; i < mp[p].size(); i++)
    {
        if (!visited[mp[p][i]])
        {
            parent[mp[p][i]] = p;
            if (dfs(mp[p][i], mp, visited, parent) == 1)
                return 1;
        }
        else
        {
            if (mp[p][i] != parent[p])
            {
                s = mp[p][i];
                d = p;
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    lol n, m;
    cin >> n >> m;
    map<lol, vector<lol>> mp;
    while (m--)
    {
        lol x, y;
        cin >> x >> y;
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    bool visited[n + 1];
    lol parent[n + 1];
    for (lol i = 0; i <= n; i++)
    {
        visited[i] = false;
        parent[i] = -1;
    }
    for (lol i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, mp, visited, parent))
            {
                stack<lol> x;
                x.push(s);
                lol cur = d;
                while (cur != s)
                {

                    x.push(cur);
                    cur = parent[cur];
                }
                x.push(cur);
                cout << x.size() << '\n';
                while (!x.empty())
                {
                    cout << x.top() << " ";
                    x.pop();
                }
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE";

    return 0;
}