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
        lol n, k;
        cin >> n >> k;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol dp[64][2];
        lol p = 0;
        lol mod = 1e9 + 7;
        for (lol i = 0; i < n; i++)
        {
            if (i == 0)
            {
                for (lol j = 0; j < 64; j++)
                {
                    dp[j][p] = 0;
                    if (j == 0)
                        dp[j][p]++;
                    if (j == a[i])
                        dp[j][p]++;
                }
                p++;
            }
            else
            {
                for (lol j = 0; j < 64; j++)
                    dp[j][p] = 0;
                for (lol j = 0; j < 64; j++)
                {
                    dp[(j & a[i])][p] += dp[j][1 - p];
                    dp[(j & a[i])][p] %= mod;
                    dp[j][p] += dp[j][1 - p];
                    dp[j][p] %= mod;
                }
                p = 1 - p;
            }
        }
        lol ans = 0;
        for (lol i = 0; i < 64; i++)
        {
            lol c = 0;
            for (lol j = 0; j < 6; j++)
            {
                if ((i & (1ll << j)))
                    c++;
            }
            if (c == k)
            {
                ans += dp[i][1 - p];
                ans %= mod;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}