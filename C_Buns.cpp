#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m, co, dx;
    cin >> n >> m >> co >> dx;
    vector<pair<lol, lol>> v;
    while (m--)
    {
        lol a, b, c, d;
        cin >> a >> b >> c >> d;
        lol f = a / b;
        while (f--)
        {
            v.push_back({c, d});
        }
    }
    lol dp[n + 1][v.size() + 1];
    for (lol i = 0; i <= n; i++)
    {
        for (lol j = 0; j <= v.size(); j++)
        {
            if (i == 0)
            {
                dp[i][j] = 0;
            }
            else if (j == 0)
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = dp[i][j - 1];
                if (i - v[j - 1].first >= 0)
                {
                    dp[i][j] = max(dp[i][j], dp[i - v[j - 1].first][j - 1] + v[j - 1].second);
                }
            }
        }
    }
    lol ans = dp[n][v.size()];
    for (lol i = 1; co * 1ll * i <= n; i++)
    {
        ans = max(ans, dp[n - co * 1ll * i][v.size()] + dx * 1ll * i);
    }
    cout << ans;

    return 0;
}