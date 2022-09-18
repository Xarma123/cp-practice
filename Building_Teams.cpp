#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    lol n, m;
    cin >> n >> m;
    map<lol, vector<lol>> mp;
    bool visited[n + 1];
    lol ans[n + 1];
    for (lol i = 0; i <= n; i++)
    {
        ans[i] = -1;
    }

    memset(visited, false, sizeof(visited));
    while (m--)
    {
        lol x, y;
        cin >> x >> y;
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    bool a = true;
    for (lol j = 1; j <= n; j++)
    {
        if (!visited[j])
        {
            queue<lol> bfs;
            bfs.push(j);
            visited[j] = true;
            ans[j] = 1;
            while (!bfs.empty())
            {
                lol x = bfs.front();
                bfs.pop();
                for (lol i = 0; i < mp[x].size(); i++)
                {
                    if (!visited[mp[x][i]])
                    {
                        visited[mp[x][i]] = true;
                        if (ans[x] == 1)
                            ans[mp[x][i]] = 2;
                        else
                            ans[mp[x][i]] = 1;
                        bfs.push(mp[x][i]);
                    }
                    else
                    {
                        if (ans[mp[x][i]] == ans[x])
                            a = false;
                    }
                }
            }
        }
    }
    if (a)
    {
        for (lol i = 1; i <= n; i++)
        {
            cout << ans[i] << " ";
        }
    }
    else
        cout << "IMPOSSIBLE";

    return 0;
}