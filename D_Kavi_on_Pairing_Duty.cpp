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
    lol div[n + 1];
    memset(div, 0, sizeof(div));
    for (lol i = 1; i <= n; i++)
    {
        for (lol j = 1; i * 1ll * j <= n; j++)
        {
            if (2ll <= j)
            {

                div[i * 1ll * j]++;
            }
        }
    }

    lol dp[n + 1];
    dp[0] = 1;
    lol m = 998244353;
    lol s = 1;
    for (lol i = 1; i <= n; i++)
    {

        dp[i] = 0;
        dp[i] += s;
        dp[i] %= m;
        dp[i] += div[i];
        dp[i] %= m;
        s += dp[i];
        s %= m;
    }

    cout << dp[n];
}