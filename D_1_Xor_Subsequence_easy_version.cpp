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
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol dp[n];

        for (lol i = 0; i < n; i++)
        {
            dp[i] = 1;
            for (lol j = i - 1; j >= 0 && j >= i - 600; j--)
            {
                if ((a[j] ^ i) < (a[i] ^ j))
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        lol ans = 0;
        for (lol i = 0; i < n; i++)
        {
            ans = max(ans, dp[i]);
        }
        cout << ans << '\n';
    }

    return 0;
}