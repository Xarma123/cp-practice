#include <bits/stdc++.h>
#define lol long long
using namespace std;
string a[1001];
lol g[1001][1001];
lol n, m, k;
lol dfs(lol i, lol j, lol c)
{
    g[i][j] = c;
    lol dx[4] = {-1, 0, 0, 1};
    lol dy[4] = {0, -1, 1, 0};
    lol q = 0;
    for (lol k = 0; k < 4; k++)
    {
        lol i1 = i + dx[k];
        lol j1 = j + dy[k];
        if (i1 < 0 || i1 >= n || j1 < 0 || j1 >= m)
            continue;
        if (g[i1][j1] != -1)
            continue;
        if (a[i1][j1] == '*')
        {
            q++;
            continue;
        }
        q += dfs(i1, j1, c);
    }
    return q;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    for (lol i = 0; i < n; i++)
        cin >> a[i];
    memset(g, -1, sizeof(g));
    lol c = 1;
    map<lol, lol> mp;
    for (lol i = 0; i < n; i++)
        for (lol j = 0; j < m; j++)
        {
            if (g[i][j] == -1 && a[i][j] == '.')
            {
                mp[c] = dfs(i, j, c);
                c++;
            }
        }
    while (k--)
    {
        lol x, y;
        cin >> x >> y;
        cout << mp[g[x - 1][y - 1]] << '\n';
    }

    return 0;
}