#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol c[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> c[i];
        }
        lol dp[n][n + 1];
        for (lol k = 0; k <= n; k++)
        {
            for (lol i = 0; i < n; i++)
            {
                if (i == 0)
                {
                    dp[i][k] = 0;
                }
                else if (k == 0)
                {
                    dp[i][k] = dp[i - 1][k];
                    if (c[i] < c[i - 1])
                        dp[i][k] = LONG_LONG_MAX;
                }
                else
                {
                    dp[i][k] = i;
                    for (lol j = i - 1; j >= 0; j--)
                    {
                        if (c[i] > c[j])
                        {
                            if (dp[j][k - 1] != LONG_LONG_MAX)
                                dp[i][k] = min(dp[i][k], dp[j][k - 1] + i - j - 1);
                        }
                    }
                    if (c[i] > c[i - 1])
                        dp[i][k] = min(dp[i][k], dp[i - 1][k]);
                }
            }
            if (k)
            {
                lol ans = LONG_LONG_MAX;
                for (lol i = 0; i < n; i++)
                {
                    if (dp[i][k - 1] != LONG_LONG_MAX)
                        ans = min(ans, dp[i][k - 1] + n - i - 1);
                }
                cout << min(ans, dp[n - 1][k]) << " ";
            }
        }
        cout << '\n';
    }
}