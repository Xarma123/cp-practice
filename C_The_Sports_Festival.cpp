#include <bits/stdc++.h>
#define lol long long
using namespace std;

int main()
{
    lol n;
    cin >> n;
    lol s[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    sort(s, s + n);
    lol dp[n][n];
    for (lol i = 0; i < n; i++)
    {
        dp[i][i] = 0;
    }
    for (lol i = 0; i < n - 1; i++)
    {
        dp[i + 1][i] = s[i + 1] - s[i];
    }
    for (lol i = 0; i < n; i++)
    {
        for (lol j = n - 1; j >= 0; j--)
        {
            if (i > j + 1)
            {
                dp[i][j] = s[i] - s[j];
                if (j + 1 < n && i - 1 >= 0)
                    dp[i][j] += min(dp[i][j + 1], dp[i - 1][j]);
            }
        }
    }
    cout << dp[n - 1][0];

    return 0;
}