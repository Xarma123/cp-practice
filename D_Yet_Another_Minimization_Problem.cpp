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
        lol a[n], b[n];
        lol sum = 0;
        lol q = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
            q += a[i] * 1ll * a[i];
        }
        for (lol i = 0; i < n; i++)
        {
            cin >> b[i];
            sum += b[i];
            q += b[i] * 1ll * b[i];
        }
        q = q * 1ll * (n - 2);
        bool dp[n + 1][sum];
        for (lol i = 0; i <= n; i++)
        {
            for (lol j = 0; j < sum; j++)
            {
                if (i == 0 && j == 0)
                    dp[i][j] = true;
                else if (i == 0)
                {
                    dp[i][j] = false;
                }
                else
                {
                    dp[i][j] = false;
                    if (j - a[i - 1] >= 0)
                        dp[i][j] |= dp[i - 1][j - a[i - 1]];
                    if (j - b[i - 1] >= 0)
                        dp[i][j] |= dp[i - 1][j - b[i - 1]];
                }
            }
        }
        lol ans = LONG_LONG_MAX;
        for (lol j = 0; j < sum; j++)
        {
            if (dp[n][j])
                ans = min(ans, q + j * 1ll * j + (sum - j) * 1ll * (sum - j));
        }
        cout << ans << endl;
    }
    return 0;
}