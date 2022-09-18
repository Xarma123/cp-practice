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
    lol a[n], b[n], c[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
    }
    lol dp[n][3];
    for (lol i = 0; i < n; i++)
    {
        if (i == 0)
        {
            dp[i][0] = a[i];
            dp[i][1] = b[i];
            dp[i][2] = c[i];
        }
        else
        {
            dp[i][0] = a[i] + max(dp[i-1][1], dp[i-1][2]);
            dp[i][1] = b[i] + max(dp[i-1][0], dp[i-1][2]);
            dp[i][2] = c[i] + max(dp[i-1][1], dp[i-1][0]);
        }
    }
    cout << max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2]));

    return 0;
}