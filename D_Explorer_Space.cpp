#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m, k;
    cin >> n >> m >> k;
    lol h[n][m - 1];
    for (lol i = 0; i < n; i++)
    {
        for (lol j = 0; j < m - 1; j++)
        {
            cin >> h[i][j];
        }
    }
    lol v[n - 1][m];
    for (lol i = 0; i < n - 1; i++)
    {
        for (lol j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }
    if (k % 2 == 0)
    {
        k /= 2;
        lol dp[n][m][k + 1];
        for (lol q = 0; q <= k; q++)
        {
            for (lol i = 0; i < n; i++)
            {
                for (lol j = 0; j < m; j++)
                {
                    dp[i][j][q] = 0;
                    if (q > 0)
                    {
                        lol f = LONG_LONG_MAX;
                        if (i - 1 >= 0)
                        {
                            f = min(f, v[i - 1][j] + dp[i - 1][j][q - 1]);
                        }
                        if (i + 1 < n)
                        {
                            f = min(f, v[i][j] + dp[i + 1][j][q - 1]);
                        }
                        if (j - 1 >= 0)
                        {
                            f = min(f, h[i][j - 1] + dp[i][j - 1][q - 1]);
                        }
                        if (j + 1 < m)
                        {
                            f = min(f, h[i][j] + dp[i][j + 1][q - 1]);
                        }
                        dp[i][j][q] += f;
                    }
                    if (q == k)
                        cout << 2ll * dp[i][j][q] << " ";
                }
                if (q == k)
                    cout << '\n';
            }
        }
    }
    else
    {
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < m; j++)
            {
                cout << -1 << " ";
            }
            cout << '\n';
        }
    }
}