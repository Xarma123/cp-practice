#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (n >= m)
    {
        cout << "YES\n";
    }
    else
    {
        bool dp[n][m];
        memset(dp, false, sizeof(dp));
        for (lol i = 0; i < n; i++)
        {
            dp[i][(a[i] % m)] = true;
            if (i)
            {
                for (lol j = 0; j < m; j++)
                {
                    dp[i][j] |= dp[i - 1][j];
                    dp[i][(j + a[i]) % m] |= dp[i - 1][j];
                }
            }
        }
        if (dp[n - 1][0])
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}