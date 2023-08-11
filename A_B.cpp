#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol dp[n];
    lol x[n], y[n], t[n];
    lol r;
    cin >> r;
    lol p[n];
    for (lol i = 0; i < n; i++)
    {
        dp[i] = 1;
        if (i - 3ll * r >= 0)
            dp[i] = 1 + p[i - 3ll * r];
        for (lol j = i - 1; j >= 0 && j >= i - 3ll * r; j--)
        {
            if ((long long)abs(x[j] - x[i]) + (long long)abs(y[j] - y[i]) <= t[i] - t[j])
                dp[i] = max(dp[i], 1 + dp[j]);
        }
        if (i == 0)
            p[i] = dp[i];
        else
            p[i] = max(p[i - 1], dp[i]);
    }
    cout << p[n - 1];
}