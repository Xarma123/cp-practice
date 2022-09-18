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
    }
    lol dp[n][3];
    dp[0][0] = 1;
    if (a[0] == 1 || a[0] == 3)
        dp[0][1] = 0;
    else
        dp[0][1] = LONG_LONG_MAX;
    if (a[0] == 2 || a[0] == 3)
        dp[0][2] = 0;
    else
        dp[0][2] = LONG_LONG_MAX;
    lol i;
    for ( i = 1; i < n; i++)
    {
        dp[i][0] = 1 + min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2]));
        if (a[i] == 1 || a[i] == 3)
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
        else
            dp[i][1] = LONG_LONG_MAX;
        if (a[i] == 2 || a[i] == 3)
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
        else
            dp[i][2] = LONG_LONG_MAX;

    }
    cout << min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2]));

    return 0;
}