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
        lol n, k;
        cin >> n >> k;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] < 0)
                a[i] = -a[i];
            a[i] %= k;
        }
        bool dp[n + 1][k];
        for (lol i = 0; i <= n; i++)
        {
            for (lol j = 0; j < k; j++)
            {
                if (i == 0 && j == 0)
                    dp[i][j] = true;
                else if (i == 0)
                    dp[i][j] = false;
                else
                {
                    dp[i][j] = dp[i - 1][(j - a[i - 1] + k) % k];
                    dp[i][j] |= dp[i - 1][(j + a[i - 1]) % k];
                }
            }
        }
        if (dp[n][0])
            cout << "Divisible" << endl;
        else
            cout << "Not divisible" << endl;
    }

    return 0;
}