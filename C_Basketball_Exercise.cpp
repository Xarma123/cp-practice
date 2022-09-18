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
    lol h1[n];
    lol h2[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> h1[i];
    }
    for (lol i = 0; i < n; i++)
    {
        cin >> h2[i];
    }
    lol dp[2][n];
    dp[0][0] = h1[0];
    dp[1][0] = h2[0];
    for (lol i = 1; i < n; i++)
    {
        dp[0][i] = dp[1][i - 1] + h1[i];
        dp[0][i] = max(dp[0][i], dp[0][i - 1]);
        dp[1][i] = dp[0][i - 1] + h2[i];
        dp[1][i] = max(dp[1][i], dp[1][i - 1]);
    }
    cout << max(dp[0][n - 1], dp[1][n - 1]);

    return 0;
}