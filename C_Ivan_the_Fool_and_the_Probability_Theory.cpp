#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    lol md = 1e9 + 7;
    lol dp[m + 1];
    dp[0] = 1;
    for (lol i = 1; i <= m; i++)
    {
        dp[i] = dp[i - 1];
        if (i - 2 >= 0)
            dp[i] += dp[i - 2];
        dp[i] %= md;
    }
    dp[m] = (2ll * dp[m]) % md;

    lol dp2[n + 1];
    dp2[0] = 1;
    for (lol i = 1; i <= n; i++)
    {
        dp2[i] = dp2[i - 1];
        if (i - 2 >= 0)
            dp2[i] += dp2[i - 2];
        dp2[i] %= md;
    }
    dp2[n] = (2ll * (dp2[n])) % md;
    cout << ((dp[m] + dp2[n] - 2) % md + md) % md;
}