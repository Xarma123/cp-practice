#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, h, l, r;
    cin >> n >> h >> l >> r;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lol dp[n][h];
    for (lol i = 0; i < n; i++)
    {
        for (lol j = 0; j < h; j++)
        {
            dp[i][j] = LONG_LONG_MIN;
        }
    }

    for (lol i = 0; i < n; i++)
    {
        if (i == 0)
        {
            if (a[i] >= l && a[i] <= r)
                dp[i][a[i]] = 1;
            else
                dp[i][a[i]] = 0;
            if (a[i] - 1 >= l && a[i] - 1 <= r)
                dp[i][a[i] - 1] = 1;
            else
                dp[i][a[i] - 1] = 0;
        }
        else
        {
            for (lol j = 0; j < h; j++)
            {
                lol x = (j + a[i]) % h;
                lol c = 0;
                if (x >= l && x <= r)
                    c++;
                dp[i][x] = max(dp[i][x], dp[i - 1][j] + c);
                x = (j + a[i] - 1) % h;
                c = 0;
                if (x >= l && x <= r)
                    c++;
                dp[i][x] = max(dp[i][x], dp[i - 1][j] + c);
            }
        }
    }
    lol ans = LONG_LONG_MIN;
    for (lol i = 0; i < h; i++)
    {
        ans = max(dp[n - 1][i], ans);
    }
    cout << ans;

    return 0;
}