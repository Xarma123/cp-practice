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
    while (m--)
    {
        lol x, y;
        cin >> x >> y;
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    bool visited[n + 1];
    memset(visited, false, sizeof(visited));
    bool ans = false;
    queue<lol> bfs;
    bfs.push(1);
    lol parent[n + 1];
    parent[1] = -1;
    visited[1] = true;
    while (!bfs.empty())
    {
        lol cur = bfs.front();
        bfs.pop();

        if (cur == n)
            ans = true;
        for (lol i = 0; i < mp[cur].size(); i++)
        {
            if (!visited[mp[cur][i]])
            {
                parent[mp[cur][i]] = cur;
                visited[mp[cur][i]] = true;
                bfs.push(mp[cur][i]);
            }
        }
    }
    if (ans)
    {
        lol cur = n;
        stack<lol> x;
        while (cur != 1)
        {
            x.push(cur);
            cur = parent[cur];
        }
        x.push(1);
        cout << x.size() << '\n';
        while (!x.empty())
        {
            cout << x.top() << " ";
            x.pop();
        }
    }
    else
        cout << "IMPOSSIBLE" << '\n';

    return 0;
}