#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i] += 1e4 + 5;
    }
    lol dp[n][2][20005];
    memset(dp, 0, sizeof(dp));
    lol ans = 0;
    lol m = 998244353;
    for (lol i = 1; i < n - 1; i++)
    {
        if (i == 1)
        {
            dp[i][0][a[i]]++;
            dp[i][1][a[i]]++;
        }
        else
        {
            for (lol j = 0; j < 20005; j++)
            {
                lol val = j;
                lol ways = dp[i - 1][0][j];
                dp[i][0][a[i] + val] += ways;
                dp[i][0][a[i] + val] %= m;
                dp[i][1][a[i] + val] += ways;
                dp[i][1][a[i] + val] %= m;
            }
        }
    }
}
for (lol j = 0; j < 20005; j++)
{
    ans += dp[n - 2][0][j];
    ans %= m;
    ans += dp[n - 2][1][j];
    ans %= m;
}

cout << ans;

return 0;
}