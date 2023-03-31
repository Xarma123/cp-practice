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
        lol n, m;
        cin >> n >> m;
        lol dp[n + 1];
        lol s = 0;
        lol ans = 0;
        for (lol i = n; i >= 2; i--)
        {
            // k<=n/i
            dp[i] = (n / i) * 1ll * ((n / i) - 1) / 2ll;
            for (lol j = i + i; j <= n; j += i)
            {
                dp[i] -= dp[j];
            }
            if (m - s >= (dp[i] / (i - 1)) * 1ll * (i - 1))
            {
                s += (dp[i] / (i - 1)) * 1ll * (i - 1);
                ans += (dp[i] / (i - 1)) * 1ll * i;
            }
            else
            {
                lol x = (m - s) / (i - 1);
                ans += x * 1ll * i;
                s += x * 1ll * (i - 1);
            }
        }
        if (s == m)
            cout << ans << '\n';
        else
            cout << -1 << '\n';
    }

    return 0;
}