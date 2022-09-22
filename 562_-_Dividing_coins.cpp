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
        lol s = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            s += a[i];
        }
        bool dp[n + 1][s / 2 + 1];
        for (lol i = 0; i <= n; i++)
        {
            for (lol j = 0; j <= s / 2; j++)
            {
                if (i == 0 && j == 0)
                    dp[i][j] = true;
                else if (i == 0)
                    dp[i][j] = false;
                else if (j == 0)
                    dp[i][j] = true;
                else
                {
                    dp[i][j] = false;
                    if (j - a[i - 1] >= 0)
                    {
                        dp[i][j] |= dp[i - 1][j - a[i - 1]];
                    }
                    dp[i][j] |= dp[i - 1][j];
                }
            }
        }
        lol mx = 0;
        for (lol i = 0; i <= s / 2; i++)
        {
            if (dp[n][i])
            {
                mx = i;
            }
        }
        cout << abs(mx - (s - mx)) << endl;
    }

    return 0;
}