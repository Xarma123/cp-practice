#include <bits/stdc++.h>
using namespace std;
#define lol long long
lol dp[5000][5001][2];
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    lol b[n + 1];
    for (lol i = 0; i < n; i++)
    {
        if (i == 0)
        {
            dp[i][0][0] = 0;
            dp[i][0][1] = LONG_LONG_MAX;
            dp[i][1][1] = 0;
            dp[i][1][0] = LONG_LONG_MAX;
            for (lol j = 2; j <= n; j++)
            {
                dp[i][j][0] = LONG_LONG_MAX;
                dp[i][j][1] = LONG_LONG_MAX;
                b[j] = a[i];
            }
            b[0] = b[1] = a[i];
        }
        else
        {
            lol nb[n + 1];
            for (lol j = 0; j <= n; j++)
            {
                dp[i][j][0] = dp[i - 1][j][0];
                nb[j] = a[i];
                if (dp[i - 1][j][1] != LONG_LONG_MAX)
                {
                    if (a[i] < a[i - 1])
                    {

                        dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j][1]);
                    }
                    else
                    {
                        if (dp[i - 1][j][1] + (a[i] - a[i - 1] + 1) <= dp[i][j][0])
                            nb[j] = a[i - 1] - 1;
                        dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j][1] + (a[i] - a[i - 1] + 1));
                    }
                }

                dp[i][j][1] = LONG_LONG_MAX;
                if (j - 1 >= 0 && dp[i - 1][j - 1][0] != LONG_LONG_MAX)
                {
                    if (a[i] > b[j - 1])
                    {
                        dp[i][j][1] = dp[i - 1][j - 1][0];
                    }
                    else
                    {

                        dp[i][j][1] = dp[i - 1][j - 1][0] + (b[j - 1] - a[i] + 1);
                    }
                }
            }

            for (lol j = 0; j <= n; j++)
                b[j] = nb[j];
        }
    }
    for (lol i = 1; i <= (n + 1) / 2; i++)
    {
        cout << min(dp[n - 1][i][0], dp[n - 1][i][1]) << " ";
    }
}