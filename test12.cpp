#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    bool dp[sum / 2 + 1][n + 1];
    for (lol i = 0; i <= sum / 2; i++)
    {
        for (lol j = 0; j <= n; j++)
        {
            if (i == 0)
                dp[i][j] = true;
            else if (j == 0)
            {
                dp[i][j] = false;
            }
            else
            {
                dp[i][j] = dp[i][j - 1];
                if (i - a[j - 1] >= 0)
                {
                    dp[i][j] |= dp[i - a[j - 1]][j - 1];
                }
            }
        }
    }
    return dp[sum / 2][n];

    return 0;
}