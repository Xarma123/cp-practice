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
    lol a[n];

    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    bool dp[2ll * n + 1];
    memset(dp, false, sizeof(dp));
    dp[a[0]] = true;
    for (lol i = 1; i < n; i++)
    {
        bool dp2[2ll * n + 1];
        for (lol j = 0; j <= 2ll * n; j++)
        {
            dp2[j] = dp[j];
        }

        for (lol j = i; j <= 2ll * n; j++)
        {
            if (dp[j])
            {
                if (j + a[i] <= 2ll * n)
                    dp2[j + a[i]] = true;
            }
        }
        for (lol j = 0; j <= 2ll * n; j++)
        {
            dp[j] = dp2[j];
        }
    }
    lol ans = 0;
    lol c = a[0];
    for (lol i = 1; i < 2ll * n + 1; i++)
    {
        if (i < n)
            c += a[i];  
        if (dp[i])
        {
            ans = max(ans, c - i);
        }
    }

    cout << ans;
}