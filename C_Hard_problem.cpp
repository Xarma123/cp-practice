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
    lol c[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    string a[n];
    lol dp[2][n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        dp[0][i] = LONG_LONG_MAX;
        dp[1][i] = LONG_LONG_MAX;
    }
    dp[0][0] = 0;
    dp[1][0] = c[0];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (lol i = 1; i < n; i++)
    {
        // 0
        if (a[i - 1] <= a[i])
        {
            dp[0][i] = min(dp[0][i], dp[0][i - 1]);
        }
        reverse(a[i - 1].begin(), a[i - 1].end());
        if (a[i - 1] <= a[i])
        {
            dp[0][i] = min(dp[0][i], dp[1][i - 1]);
        }
        reverse(a[i - 1].begin(), a[i - 1].end());

        reverse(a[i].begin(), a[i].end());
        if (a[i - 1] <= a[i])
        {
            dp[1][i] = min(dp[1][i], dp[0][i - 1] + c[i]);
        }
        reverse(a[i - 1].begin(), a[i - 1].end());
        if (a[i - 1] <= a[i])
        {
            dp[1][i] = min(dp[1][i], dp[1][i - 1] + c[i]);
        }
        reverse(a[i - 1].begin(), a[i - 1].end());
        reverse(a[i].begin(), a[i].end());
    }
    if (min(dp[0][n - 1], dp[1][n - 1]) == LONG_LONG_MAX)
        cout << -1;
    else
        cout << min(dp[0][n - 1], dp[1][n - 1]);

    return 0;
}