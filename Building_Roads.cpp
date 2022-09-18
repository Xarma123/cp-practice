#include <bits/stdc++.h>
#define lol long long
using namespace std;
void dfs(lol i, map<lol, vector<lol>> &mp, bool visisted[])
{
    visisted[i] = true;
    for (lol j = 0; j < mp[i].size(); j++)
    {
        if (!visisted[mp[i][j]])
        {
            dfs(mp[i][j], mp, visisted);
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    lol n, m;
    cin >> n >> m;
    map<lol, vector<lol>> mp;
    bool visited[n + 1];
    memset(visited, false, sizeof(visited));
    while (m--)
    {
        lol x, y;
        cin >> x >> y;
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    vector<lol> c;
    for (lol i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            c.push_back(i);
            dfs(i, mp, visited);
        }
    }
    cout << c.size() - 1 << '\n';
    for (lol i = 0; i < c.size() - 1; i++)
    {
        cout << c[i] << " " << c[i + 1] << '\n';
    }

    return 0;
}