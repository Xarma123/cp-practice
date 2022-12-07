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
    lol k;
    cin >> k;
    lol n = 1e5 + 1;
    lol m = 1e9 + 7;
    lol dp[n + 1];
    for (lol i = 0; i <= n; i++)
    {
        if (i < k)
        {
            dp[i] = 1;
        }
        else
        {
            dp[i] = (dp[i - 1] + dp[i - k]) % m;
        }
    }
    for (lol i = 1; i <= n; i++)
    {
        dp[i] = (dp[i] + dp[i - 1]) % m;
    }
    while (t--)
    {
        lol a, b;
        cin >> a >> b;
        cout << ((dp[b] - dp[a - 1]) % m + m) % m << endl;
    }

    return 0;
}