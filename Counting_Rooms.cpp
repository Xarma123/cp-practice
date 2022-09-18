#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol n, m;
void dfs1(lol x, lol y, vector<vector<bool>> &visited)
{
    if (x >= 0 && x < n && y >= 0 && y < m)
    {
        if (visited[x][y])
            return;
        visited[x][y] = true;
    }
    else
        return;

    dfs1(x + 1, y, visited);
    dfs1(x - 1, y, visited);
    dfs1(x, y - 1, visited);
    dfs1(x, y + 1, visited);
}
lol dfs(vector<vector<bool>> &visited)
{
    lol c = 0;
    for (lol i = 0; i < n; i++)
    {
        for (lol j = 0; j < m; j++)
        {
            if (!visited[i][j])
            {
                c++;
                dfs1(i, j, visited);
            }
        }
    }
    return c;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    vector<vector<bool>> visited;

    for (lol i = 0; i < n; i++)
    {
        vector<bool> y;
        for (lol j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            if (c == '.')
                y.push_back(false);
            else
                y.push_back(true);
        }
        visited.push_back(y);
    }

    cout << dfs(visited);

    return 0;
}