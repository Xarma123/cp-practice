#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m, k;
    cin >> n >> m >> k;
    lol a[n], c[n + 1];
    c[0] = 0;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        c[i + 1] = c[i] + a[i];
    }
    lol dp[n + 1][k + 1];
    for (lol i = 0; i <= n; i++)
    {
        for (lol j = 0; j <= k; j++)
        {
            if (i == 0)
            {
                dp[i][j] = 0;
            }
            else if (j == 0)
                dp[i][j] = 0;
            else
            {
                dp[i][j] = dp[i - 1][j];
                if (i >= m)
                {
                    dp[i][j] = max(dp[i][j], c[i] - c[i - m] + dp[i - m][j - 1]);
                }
            }
        }
    } 
    cout<<dp[n][k];

    return 0;
}