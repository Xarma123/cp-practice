#include <bits/stdc++.h>
#define lol long double
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    lol p[n];
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }

    lol dp[n + 1][n + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = 1;
            }
            else if (i == 0)
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = (1 - p[i - 1]) * (dp[i - 1][j]);
                if (j - 1 >= 0)
                    dp[i][j] += (p[i - 1]) * (dp[i - 1][j - 1]);
            }
        }
    }
    lol ans = 0;
    for (int i = n / 2 + 1; i <= n; i++)
    {
        ans += dp[n][i];
    }
    cout << setprecision(10) << ans;

    return 0;
}