#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    pair<double, lol> p[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> p[i].second >> p[i].first;
    }
    sort(p, p + n);
    lol dp[n][m];
    lol c[m];
    for (lol i = 0; i < n; i++)
    {
        for (lol j = 0; j < m; j++)
        {
            if (i == 0)
            {
                if (p[i].second == j + 1)
                {
                    dp[i][j] = 1;
                }
                else
                    dp[i][j] = 0;
            }
            else
            {
                if (p[i].second == j + 1)
                    dp[i][j] = max(dp[i - 1][j], c[j] + 1);
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        for (lol j = 0; j < m; j++)
        {
            if (j == 0)
                c[j] = dp[i][j];
            else
                c[j] = max(dp[i][j], c[j - 1]);
        }
    }
    lol ans = LONG_LONG_MAX;
    for (lol i = 0; i < m; i++)
    {
        ans = min(ans, n - dp[n - 1][i]);
    }

    cout << ans;

    return 0;
}