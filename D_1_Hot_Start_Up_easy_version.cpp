#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, k;
        cin >> n >> k;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol co[k + 1], ho[k + 1];
        for (lol i = 1; i <= k; i++)
        {
            cin >> co[i];
        }
        for (lol i = 1; i <= k; i++)
        {
            cin >> ho[i];
        }
        lol dp[k + 1];
        for (lol i = 0; i <= k; i++)
        {
            dp[i] = LONG_LONG_MAX;
        }
        dp[0] = 0;
        lol l = 0;
        lol ans = LONG_LONG_MAX;
        for (lol i = 0; i < n; i++)
        {
            lol ndp[k + 1];
            for (lol j = 0; j <= k; j++)
            {
                ndp[j] = LONG_LONG_MAX;
            }
            for (lol j = 0; j <= k; j++)
            {
                // j  l
                if (dp[j] != LONG_LONG_MAX)
                {
                    // a[i] l
                    if (j == a[i])
                        ndp[l] = min(ndp[l], dp[j] + ho[a[i]]);
                    else
                        ndp[l] = min(ndp[l], dp[j] + co[a[i]]);
                    // j a[i]
                    if (l == a[i])
                        ndp[j] = min(ndp[j], dp[j] + ho[a[i]]);
                    else
                        ndp[j] = min(ndp[j], dp[j] + co[a[i]]);
                }
            }
            l = a[i];
            for (lol j = 0; j <= k; j++)
            {
                if (i == n - 1)
                {
                    ans = min(ans, ndp[j]);
                }
                dp[j] = ndp[j];
            }
        }
        cout << ans << '\n';
    }
}