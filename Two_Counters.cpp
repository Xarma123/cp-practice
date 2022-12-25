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
        lol ti[m];
        for (lol i = 0; i < m; i++)
        {
            cin >> ti[i];
        }
        lol c[m];
        for (lol i = 0; i < m; i++)
        {
            cin >> c[i];
        }
        // o-z+2  2  , 3 , 4 , 1 0
        lol dp[m + 1][5];
        for (lol i = 0; i <= m; i++)
        {
            if (i == 0)
            {
                dp[i][3] = LONG_LONG_MIN;
                dp[i][1] = LONG_LONG_MIN;
                dp[i][2] = 0;
                dp[i][0] = LONG_LONG_MIN;
                dp[i][4] = LONG_LONG_MIN;
            }
            else
            {
                lol q;
                if (i == 1)
                    q = ti[i - 1];
                else
                    q = ti[i - 1] - ti[i - 2];
                if (q % 2 == 0)
                {
                    lol g[5];
                    for (lol j = 0; j < 5; j++)
                    {
                        g[j] = dp[i - 1][j];
                        if (j - 2 >= 0 && q >= 2)
                            g[j] = max(g[j], dp[i - 1][j - 2]);
                        if (j + 2 < 5 && q >= 2)
                            g[j] = max(g[j], dp[i - 1][j + 2]);
                        if (j - 4 >= 0 && q >= 4)
                            g[j] = max(g[j], dp[i - 1][j - 4]);
                        if (j + 4 < 5 && q >= 4)
                            g[j] = max(g[j], dp[i - 1][j + 4]);
                    }
                    for (lol j = 0; j < 5; j++)
                        dp[i - 1][j] = g[j];
                }
                else
                {
                    lol g[5];
                    for (lol j = 0; j < 5; j++)
                    {
                        g[j] = LONG_LONG_MIN;
                        if (j - 1 >= 0 && q >= 1)
                            g[j] = max(g[j], dp[i - 1][j - 1]);
                        if (j + 1 < 5 && q >= 1)
                            g[j] = max(g[j], dp[i - 1][j + 1]);
                        if (j - 3 >= 0 && q >= 3)
                            g[j] = max(g[j], dp[i - 1][j - 3]);
                        if (j + 3 < 5 && q >= 3)
                            g[j] = max(g[j], dp[i - 1][j + 3]);
                    }
                    for (lol j = 0; j < 5; j++)
                        dp[i - 1][j] = g[j];
                }

                if (c[i - 1] == 1)
                {

                    dp[i][2] = max(dp[i - 1][2], dp[i - 1][1]);
                    dp[i][2] = max(dp[i][2], dp[i - 1][0]);
                    dp[i][1] = LONG_LONG_MIN;
                    dp[i][0] = LONG_LONG_MIN;
                    dp[i][3] = dp[i - 1][3] + 1;
                    dp[i][4] = dp[i - 1][4] + 1;
                }
                else
                {
                    dp[i][2] = max(dp[i - 1][2], dp[i - 1][3]);
                    dp[i][2] = max(dp[i][2], dp[i - 1][4]);
                    dp[i][3] = LONG_LONG_MIN;
                    dp[i][4] = LONG_LONG_MIN;
                    dp[i][1] = dp[i - 1][1] + 1;
                    dp[i][0] = dp[i - 1][0] + 1;
                }
            }
        }
        lol q = n - ti[m - 1];
        if (q % 2 == 0)
        {
            lol g[5];
            for (lol j = 0; j < 5; j++)
            {
                g[j] = dp[m][j];
                if (j - 2 >= 0 && q >= 2)
                    g[j] = max(g[j], dp[m][j - 2]);
                if (j + 2 < 5 && q >= 2)
                    g[j] = max(g[j], dp[m][j + 2]);
                if (j - 4 >= 0 && q >= 4)
                    g[j] = max(g[j], dp[m][j - 4]);
                if (j + 4 < 5 && q >= 4)
                    g[j] = max(g[j], dp[m][j + 4]);
            }
            for (lol j = 0; j < 5; j++)
                dp[m][j] = g[j];
        }
        else
        {
            lol g[5];
            for (lol j = 0; j < 5; j++)
            {
                g[j] = LONG_LONG_MIN;
                if (j - 1 >= 0 && q >= 1)
                    g[j] = max(g[j], dp[m][j - 1]);
                if (j + 1 < 5 && q >= 1)
                    g[j] = max(g[j], dp[m][j + 1]);
                if (j - 3 >= 0 && q >= 3)
                    g[j] = max(g[j], dp[m][j - 3]);
                if (j + 3 < 5 && q >= 3)
                    g[j] = max(g[j], dp[m][j + 3]);
            }
            for (lol j = 0; j < 5; j++)
                dp[m][j] = g[j];
        }

        lol ans = LONG_LONG_MIN;
        for (lol i = 0; i < 5; i++)
        {
            ans = max(ans, dp[m][i]);
        }
        cout << ans << endl;
    }

    return 0;
}