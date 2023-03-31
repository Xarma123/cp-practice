#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, k;
    cin >> n >> k;
    lol mod = 998244353;
    lol ans[n + 1];
    memset(ans, 0, sizeof(ans));
    lol dp[n + 1][2];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    lol c = 0;
    for (lol x = k; x < k + 650; x++)
    {
        for (lol i = 0; i <= n; i++)
        {
            if (i - x >= 0)
                dp[i][c] += dp[i - x][c];
            dp[i][c] %= mod;
        }
        for (lol i = 0; i <= n; i++)
        {
            if (i - x >= 0)
                dp[i][1 - c] = dp[i - x][c];
            else
                dp[i][1 - c] = 0;

            ans[i] += dp[i][1 - c];
            ans[i] %= mod;
        }
        c = 1 - c;
    }
    for (lol i = 1; i <= n; i++)
    {
        cout << ans[i] << ' ';
    }

    return 0;
}