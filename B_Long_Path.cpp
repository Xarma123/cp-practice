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
    lol m = 1e9 + 7;
    lol dp[2][n];
    lol c[n + 1];
    c[0] = 0;
    for (lol i = 0; i < n; i++)
    {
        c[i + 1] = c[i];
        if (i == 0)
        {
            dp[0][i] = 0;

            dp[1][i] = 1;
        }
        else
        {

            dp[1][i] = dp[0][i] = (dp[1][i - 1] + 1) % m;

            dp[1][i] += (i + 2 - a[i]) % m;
            dp[1][i] %= m;
            dp[1][i] += (c[i] - c[a[i] - 1] + m) % m;
            dp[1][i] %= m;
        }

        c[i + 1] += (dp[1][i] - dp[0][i] + m) % m;
        c[i + 1] %= m;
    }
    cout << (dp[1][n - 1] + 1) % m;

    return 0;
}