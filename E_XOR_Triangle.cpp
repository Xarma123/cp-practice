#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lol b[m];
    for (lol i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    lol c[n + 1];
    c[0] = 0;
    for (lol i = 0; i < n; i++)
    {
        c[i + 1] = a[i] + c[i];
    }

    lol dp[n + 1][(1ll << m)];

    lol bb[(1ll << m)];
    for (lol i = 0; i < (1ll << m); i++)
    {
        bb[i] = 0;
        for (lol j = 0; j < m; j++)
        {
            if ((i & (1ll << j)) > 0)
            {
                bb[i] += b[j];
            }
        }
    }
    for (lol i = 0; i <= n; i++)
    {
        if (i == 0)
        {
            for (lol j = 0; j < (1ll << m); j++)
            {
                dp[i][j] = LONG_LONG_MIN;
            }
            dp[0][0] = 0;
        }
        else
        {
            for (lol j = 0; j < (1ll << m); j++)
            {
                dp[i][j] = dp[i - 1][j];
            }
            for (lol j = 0; j < (1ll << m); j++)
            {
                if (i - bb[j] >= 0)
                {
                    for (lol k = 0; k < (1ll << m); k++)
                    {
                        if ((k & j) == 0)
                        {
                            dp[i][(j | k)] = max(dp[i][(j | k)], dp[i - bb[j]][k] + c[i] - c[i - bb[j]]);
                        }   
                    }
                }
            }
        }
    }
    lol ans = LONG_LONG_MIN;
    for (lol j = 0; j < (1ll << m); j++)
    {
        ans = max(ans, dp[n][j]);
    }
    cout << ans;
}