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
        for (lol j = i - 1; j >= i - k && j >= 0; j--)
        {
            dp[i] = min(dp[i], dp[j] + abs(h[i] - h[j]));
        }
    }
    cout << dp[n - 1];

    return 0;
}