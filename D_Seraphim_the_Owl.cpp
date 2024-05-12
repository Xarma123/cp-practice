#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, m;
        cin >> n >> m;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol b[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        lol dp[n][2];
        for (lol i = n - 1; i >= 0; i--)
        {
            if (i == n - 1)
            {
                dp[i][0] = a[i];
                dp[i][1] = b[i];
            }
            else
            {
                dp[i][0] = a[i] + min(dp[i + 1][0], dp[i + 1][1]);
                dp[i][1] = b[i] + min(dp[i + 1][0], dp[i + 1][1]);
            }
        }
        lol ans = LONG_LONG_MAX;
        for (lol i = 0; i < m; i++)
        {
            ans = min(ans, dp[i][0]);
        }
        cout << ans << '\n';
    }

    return 0;
}
