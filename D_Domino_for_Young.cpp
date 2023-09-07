#include <bits/stdc++.h>
using namespace std;
#define lol long long
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
    for (lol i = 0; i < n; i++)
    {
        if (i == 0)
        {
            dp[i][0] = a[i] / 2;
            dp[i][1] = 0;
            dp[i][2] = 0;
        }
        else
        {
            dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2])) + a[i] / 2;
            dp[i][1] = 0;
            if (dp[i - 1][2])
                dp[i][1] = dp[i - 1][2] + (a[i] - 1) / 2 + 1;

            dp[i][1] = max(dp[i][1], dp[i - 1][0] - (a[i - 1] / 2) + ((a[i - 1] - 1) / 2) + ((a[i] - 1) / 2) + 1);

            dp[i][2] = 0;
            if (a[i] >= 2)
            {
                dp[i][2] = dp[i - 1][1] - ((a[i - 1] - 1) / 2) + ((a[i - 1] - 2) / 2) + ((a[i] - 2) / 2) + 1;

                dp[i][2] = max(dp[i][2], dp[i - 1][0] - (a[i - 1] / 2) + ((a[i - 1] - 2) / 2) + ((a[i] - 2) / 2) + 1);
            }
        }
    }
    cout << max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2]));
}