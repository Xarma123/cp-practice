#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m, q;
    cin >> n >> m >> q;
    lol g[n + 1][n + 1];
    for (lol i = 0; i <= n; i++)
    {
        for (lol j = 0; j <= n; j++)
        {
            g[i][j] = LONG_LONG_MAX;
        }
    }

    for (lol i = 0; i <= n; i++)
    {
        g[i][i] = 0;
    }

    while (m--)
    {
        lol a, b, c;
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c);
        g[b][a] = min(g[b][a], c);
    }
    for (lol k = 1; k <= n; k++)
    {
        for (lol i = 1; i <= n; i++)
        {
            for (lol j = 1; j <= n; j++)
            {
                if (g[i][k] != LONG_LONG_MAX && g[k][j] != LONG_LONG_MAX)
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                if (g[j][k] != LONG_LONG_MAX && g[k][i] != LONG_LONG_MAX)
                    g[i][j] = min(g[i][j], g[j][k] + g[k][i]);
            }
        }
    }
    while (q--)
    {
        lol a, b;
        cin >> a >> b;
        if (g[a][b] == LONG_LONG_MAX)
            cout << -1 << '\n';
        else
            cout << g[a][b] << '\n';
    }

    return 0;
}