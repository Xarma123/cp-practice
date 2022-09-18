#include <bits/stdc++.h>
#define lol int
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);
 
    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);
    lol n, x;
    cin >> n >> x;
    lol c[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> c[i];
        c[i] = c[i] * (n - i);
    }
    lol dp[x + 1][n + 1];
    for (lol i = 0; i <= x; i++)
    {
        for (lol j = 0; j <= n; j++)
        {
            if (i == 0)
                dp[i][j] = 0;
            else if (j == 0)
                dp[i][j] = 0;
            else
            {
                dp[i][j] = dp[i][j - 1];
                if (i - c[j - 1] >= 0)
                {
                    dp[i][j] = max(dp[i][j], dp[i - c[j - 1]][j - 1] + 1);
                }
            }
        }
    }
    cout << dp[x][n] << endl;

    return 0;
}