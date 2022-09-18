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
    lol h[n];
    lol dp[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> h[i];
        dp[i] = LONG_LONG_MAX;
    }

    dp[0] = 0;
    for (lol i = 1; i < n; i++)
    {
        if (i + 1 < n)
        {
            dp[i + 1] = min(dp[i] + abs(h[i + 1] - h[i]), dp[i + 1]);
        }
        if (i + 2 < n)
        {
            dp[i + 2] = min(dp[i] + abs(h[i + 2] - h[i]), dp[i + 2]);
        }
    }
    cout << dp[n - 1];

    return 0;
}