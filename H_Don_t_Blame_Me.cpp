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
        lol dp[n][64];
        lol mod = 1e9 + 7;
        memset(dp, 0, sizeof(dp));
        dp[0][a[0]]++;
        for (lol i = 1; i < n; i++)
        {
            for (lol j = 0; j < 64; j++)
            {
                dp[i][j] += dp[i - 1][j];
                dp[i][j] %= mod;
                dp[i][(a[i] & j)] += dp[i - 1][j];
                dp[i][(a[i] & j)] %= mod;
            }
            dp[i][a[i]]++;
            dp[i][a[i]] %= mod;
        }
        
        lol ans = 0;
        for (lol i = 0; i < 64; i++)
        {
            lol c = 0;
            for (lol j = 0; j < 8; j++)
            {
                if ((i & (1ll << j)))
                    c++;
            }
            if (c == k)
            {
                ans += dp[n - 1][i];
                ans %= mod;
            }
        }
        cout << ans << '\n';    
    }

    return 0;
}