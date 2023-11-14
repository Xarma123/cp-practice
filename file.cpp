#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lol dp[n][n][3];
    for (lol l = 0; l < n; l++)
    {
        for (lol i = 0, j = l; j < n; i++, j++)
        {
            for (lol q = 0; q < 3ll; q++)
            {
                if (l + 1 == 1)
                {
                    dp[i][j][q] = 0;
                }
                else if (l + 1 == 2)
                {
                    dp[i][j][q] = 1;
                }
                else if (q == 0)
                {
                    lol v = a[i] + a[i + 1];
                    dp[i][j][q] = 1;
                    // i+2  j
                    if (i + 3 <= j && a[i + 2] + a[i + 3] == v)
                        dp[i][j][q] = max(dp[i][j][q], 1 + dp[i + 2][j][0]);
                    if (j - 1 >= i + 2 && a[j] + a[j - 1] == v)
                        dp[i][j][q] = max(dp[i][j][q], 1 + dp[i + 2][j][1]);
                    if (i + 2 != j && a[i + 2] + a[j] == v)
                        dp[i][j][q] = max(dp[i][j][q], 1 + dp[i + 2][j][2]);
                }
                else if (q == 1)
                {
                    lol v = a[j] + a[j - 1];
                    dp[i][j][q] = 1;
                    // i  j-2
                    if (i + 3 <= j && a[i] + a[i + 1] == v)
                        dp[i][j][q] = max(dp[i][j][q], 1 + dp[i][j - 2][0]);
                    if (j - 1 >= i + 2 && a[j - 2] + a[j - 3] == v)
                        dp[i][j][q] = max(dp[i][j][q], 1 + dp[i][j - 2][1]);
                    if (i != j - 2 && a[i] + a[j - 2] == v)
                        dp[i][j][q] = max(dp[i][j][q], 1 + dp[i][j - 2][2]);
                }
                else
                {
                    lol v = a[i] + a[j];
                    dp[i][j][q] = 1;
                    // i+1   j-1
                    if (i + 3 <= j && a[i + 1] + a[i + 2] == v)
                    {
                        dp[i][j][q] = max(dp[i][j][q], 1 + dp[i + 1][j - 1][0]);
                    }
                    if (j - 2 >= i + 1 && a[j - 2] + a[j - 1] == v)
                        dp[i][j][q] = max(dp[i][j][q], dp[i + 1][j - 1][1] + 1);
                    if (i + 1 != j - 1 && a[i + 1] + a[j - 1] == v)
                    {
                        dp[i][j][q] = max(dp[i][j][q], dp[i + 1][j - 1][q] + 1);
                    }
                }
            }
        }
    }
    cout << max(dp[0][n - 1][0], max(dp[0][n - 1][1], dp[0][n - 1][2]));

    return 0;
}
