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
        lol n;
        cin >> n;
        lol k;
        cin >> k;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        pair<lol, lol> dp[2][n];
        dp[0][0].first = a[0] - k;
        dp[0][0].second = 1;

        dp[1][0].first = a[0] / 2;
        dp[1][0].second = 2;
        for (lol i = 1; i < n; i++)
        {
            lol p = dp[0][i - 1].first;
            lol d = dp[0][i - 1].second;

            dp[0][i].first = a[i] / d - k + p;
            dp[0][i].second = d;

            d = d * 1ll * 2;
            dp[1][i].first = a[i] / d + p;
            dp[1][i].second = d;

            p = dp[1][i - 1].first;
            d = dp[1][i - 1].second;

            if (a[i] / d - k + p > dp[0][i].first)
            {
                dp[0][i].first = a[i] / d - k + p;
                dp[0][i].second = d;
            }
            else if (a[i] / d - k + p == dp[0][i].first)
            {
                dp[0][i].second = min(d, dp[0][i].second);
            }

            d = d * 1ll * 2;

            if (a[i] / d + p > dp[1][i].first)
            {
                dp[1][i].first = a[i] / d + p;
                dp[1][i].second = d;
            }
            else if (a[i] / d + p == dp[1][i].first)
            {
                dp[1][i].second = min(d, dp[1][i].second);
            }
        }
        cout << max(dp[0][n - 1].first, dp[1][n - 1].first) << endl;
    }

    return 0;
}