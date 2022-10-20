#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[n];
        string s;
        cin >> s;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol dp[n][2];
        // 0 without lid
        if (s[0] == '0')
            dp[0][0] = 0;
        else
            dp[0][0] = LONG_LONG_MIN;
        // 1 with lid
        if (s[0] == '0')
            dp[0][1] = LONG_LONG_MIN;
        else
            dp[0][1] = a[0];

        for (lol i = 1; i < n; i++)
        {
            if (s[i] == '0')
            {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
                dp[i][1] = LONG_LONG_MIN;
            }
            else
            {
                dp[i][1] = a[i] + max(dp[i - 1][0], dp[i - 1][1]);
                if (dp[i - 1][0] != LONG_LONG_MIN)
                    dp[i][0] = dp[i - 1][0] + a[i - 1];
                else
                    dp[i][0] = LONG_LONG_MIN;
            }
        }
        cout << max(dp[n - 1][0], dp[n - 1][1]) << endl;
    }

    return 0;
}