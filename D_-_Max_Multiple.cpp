#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, K, d;
    cin >> n >> K >> d;
    lol a[n];
    lol dp[n][K + 1][d];

    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (lol i = 0; i < n; i++)
    {
        for (lol j = 0; j <= K; j++)
        {
            for (lol k = 0; k < d; k++)
            {
                if (i == 0)
                {
                    dp[i][j][k] = -1;
                    if (1 == j && (a[i] % d == k))
                        dp[i][j][k] = a[i];
                    if (j == 0 && k == 0)
                    {
                        dp[i][j][k] = 0;
                    }
                }
                else
                {
                    dp[i][j][k] = dp[i - 1][j][k];
                    if (j)
                    {
                        if (k >= (a[i] % d) && dp[i - 1][j - 1][k - (a[i] % d)] != -1)
                            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k - (a[i] % d)] + a[i]);
                        if (k < (a[i] % d) && dp[i - 1][j - 1][d - (a[i] % d) + k] != -1)
                            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][d - (a[i] % d) + k] + a[i]);
                    }
                }
            }
        }
    }
    cout << dp[n - 1][K][0];

    return 0;
}