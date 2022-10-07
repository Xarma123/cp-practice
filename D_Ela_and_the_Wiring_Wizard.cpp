#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, m;
        cin >> n >> m;
        lol d[n + 1][n + 1], o[n + 1][n + 1];
        for (lol i = 0; i <= n; i++)
        {
            for (lol j = 0; j <= n; j++)
            {
                d[i][j] = LONG_LONG_MAX;
                o[i][j] = LONG_LONG_MAX;
            }
        }
        while (m--)
        {
            lol a, b, c;
            cin >> a >> b >> c;
            d[a][b] = min(d[a][b], c);
            d[b][a] = min(d[b][a], c);
            o[a][b] = d[a][b];
            o[b][a] = d[b][a];
        } 
       
        for (lol i = 1; i <= n; i++)
        {
            for (lol j = 1; j <= n; j++)
            {
                for (lol k = 1; k <= n; k++)
                {
                    if (j != i && k != i && j != k)
                    {
                        if (o[j][i] != LONG_LONG_MAX)
                            d[j][k] = min(d[j][k], 2 * 1ll * o[j][i]);
                        if (o[i][k] != LONG_LONG_MAX)
                            d[j][k] = min(d[j][k], 2 * 1ll * o[i][k]);
                        d[k][j] = d[j][k];
                    }
                }
            }
        }
         
        // for (lol k = 1; k <= n; k++)
        // {
        //     for (lol i = 1; i <= n; i++)
        //     {
        //         for (lol j = 1; j <= n; j++)
        //         {
        //             if ((d[k][j] != LONG_LONG_MAX && d[i][k] != LONG_LONG_MAX) && d[i][j] > (d[i][k] + d[k][j]))
        //                 d[i][j] = d[i][k] + d[k][j];
        //         }
        //     }
        // }
        // cout << d[1][n] << endl;
    }

    return 0;
}