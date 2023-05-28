#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol a[1001][1001];
bool vis[1001][1001];
lol n, m;
lol dfs(lol px, lol py)
{
    lol dx[4] = {0, -1, 1, 0};
    lol dy[4] = {-1, 0, 0, 1};
    lol v = a[px][py];
    vis[px][py] = true;
    for (lol i = 0; i < 4; i++)
    {
        if (px + dx[i] >= 0 && px + dx[i] < n && py + dy[i] >= 0 && py + dy[i] < m)
        {
            if (vis[px + dx[i]][py + dy[i]] == false && a[px + dx[i]][py + dy[i]])
                v += dfs(px + dx[i], py + dy[i]);
        }
    }
    return v;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        memset(vis, false, sizeof(vis));
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }
        lol ans = 0;
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < m; j++)
            {
                if (vis[i][j] == false && a[i][j])
                {
                    ans = max(ans, dfs(i, j));
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}