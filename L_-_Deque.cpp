#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lol dp[n][n];
    for (lol len = 0; len < n; len++)
    {
        for (lol i = 0, j = len; i < n && j < n; i++, j++)
        {
            if (i == j)
            {
                dp[i][j] = a[i];
            }
            else
            {
                dp[i][j] = max(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1]);
            }
        }
    } 
    cout<<dp[0][n-1];

    return 0;
}