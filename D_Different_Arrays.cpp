#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol dp[300][200005];
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
    memset(dp, 0ll, sizeof(dp));
    lol m = 998244353;
    lol d = 200005;
    lol off = 90005;
    for (lol i = 1; i < n; i++)
    {
        if (i == 1)
        {
            dp[i][a[i] + off]++;
        }
        else
        {
            for (lol j = 0; j < d; j++)
            {
                if (j + a[i] < d)
                {
                    dp[i][j + a[i]] += dp[i - 1][j];
                    dp[i][j + a[i]] %= m;
                }
                if (j != off)
                {
                    if (a[i] - j + 2ll * off >= 0 && a[i] - j + 2ll * off < d)
                    {
                        dp[i][a[i] - j + 2ll * off] += dp[i - 1][j];
                        dp[i][a[i] - j + 2ll * off] %= m;
                    }
                }
            }
        }
    }
    lol ans = 0;
    for (lol i = 0; i < d; i++)
    {
        ans += dp[n - 1][i];
        ans %= m;
    }
    cout << ans;

    return 0;
}