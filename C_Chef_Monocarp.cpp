#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol q;
    cin >> q;
    while (q--)
    {
        lol n;
        cin >> n;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        lol dp[n + 1][3 * n];
        for (lol i = 0; i < 3 * n; i++)
        {
            dp[0][i] = 0;
        }
        for (lol i = 1; i <= n; i++)
            dp[i][0] = 1e18;
        for (lol i = 1; i <= n; i++)
        {
            for (lol j = 1; j < 3 * n; j++)
            {
                dp[i][j] = abs(a[i - 1] - j) + dp[i - 1][j - 1];
                dp[i][j] = min(dp[i][j], dp[i][j - 1]);
            }
        }
        cout << dp[n][3 * n - 1] << endl;
    }

    return 0;
}