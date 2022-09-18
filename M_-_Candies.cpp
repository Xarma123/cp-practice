#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, k;
    cin >> n >> k;
    lol m = 1e9 + 7;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lol dp[n + 1][k + 1];
    for (lol i = 0; i <= n; i++)
    {

        for (lol j = 0; j <= k; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = 1;
            else if (i == 0)
            {
                dp[i][j] = 0;
            }
            else if (j == 0)
                dp[i][j] = 1;
            else
            {
                dp[i][j] = 0;
                if (j - a[i - 1] - 1 >= 0)
                    dp[i][j] = (dp[i - 1][j] - dp[i - 1][j - a[i - 1] - 1] + m) % m;
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        for (lol j = 1; j <= k; j++)
        {
            dp[i][j] += (dp[i][j - 1]) % m;
            dp[i][j] %= m;
        }
    }
    if (k > 0)
        cout << (dp[n][k] - dp[n][k - 1] + m) % m;
    else
        cout << dp[n][k];
    return 0;
}