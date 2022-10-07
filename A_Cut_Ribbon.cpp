#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, a, b, c;
    cin >> n >> a >> b >> c;
    lol dp[n + 1];
    dp[0] = 0;
    for (lol i = 1; i <= n; i++)
    {
        dp[i] = -1e9;
        if (i - a >= 0 && dp[i - a] > -1e9)
            dp[i] = max(dp[i], dp[i - a] + 1);
        if (i - b >= 0 && dp[i - b] > -1e9)
            dp[i] = max(dp[i], dp[i - b] + 1);
        if (i - c >= 0 && dp[i - c] > -1e9)
            dp[i] = max(dp[i], dp[i - c] + 1);
    }
    cout << dp[n];

    return 0;
}