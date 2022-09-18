#include <bits/stdc++.h>
#define lol long long
using namespace std;
bool vis[55][55];
lol n, m;
bool dfs(lol i, lol j, lol pi, lol pj, string a[], char c)
{
    if (i >= n || i < 0 || j >= m || j < 0)
        return false;
    if (a[i][j] != c)
        return false;
    if (vis[i][j])
        return true;
    vis[i][j] = true;
    lol dx[4] = {-1, 0, 0, 1};
    lol dy[4] = {0, 1, -1, 0};
    for (lol q = 0; q < 4; q++)
    {
        if (!(i + dx[q] == pi && j + dy[q] == pj))
        {
            if (dfs(i + dx[q], j + dy[q], i, j, a, c))
                return true;
        }
    }
    return false;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    string a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    memset(vis, false, sizeof(vis));
    bool ans = false;
    for (lol i = 0; i < n; i++)
    {
        for (lol j = 0; j < m; j++)
        {
            if (!vis[i][j])
            {
                ans |= dfs(i, j, -1, -1, a, a[i][j]);
            }
            if (ans)
                break;
        }
        if (ans)
            break;
    }
    if(ans)
    cout<<"Yes";
    else
    cout<<"No";

    return 0;
}