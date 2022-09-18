#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol m = 1000000007;
int main()
{
    lol n, l, r;
    cin >> n >> l >> r;
    lol a[3] = {0, 0, 0};

    lol k = (r - l) / 3;
    a[l % 3] += (k + 1);
    l++;
    if (l <= r)
    {
        k = (r - l) / 3;
        a[l % 3] += (k + 1);
    }
    l++;
    if (l <= r)
    {
        k = (r - l) / 3;
        a[l % 3] += (k + 1);
    }
    lol dp[n][3];
    for (lol i = 0; i < n; i++)
    {
        if (i == 0)
        {
            dp[i][0] = a[0];
            dp[i][1] = a[1];
            dp[i][2] = a[2];
        }
        else
        {
            dp[i][0] = (((dp[i - 1][0] * 1ll * a[0]) % (m) + (dp[i - 1][1] * 1ll * a[2]) % (m)) % m + (dp[i - 1][2] * 1ll * a[1]) % (m)) % (m);
            dp[i][1] = (((dp[i - 1][0] * 1ll * a[1]) % (m) + (dp[i - 1][1] * 1ll * a[0]) % (m)) % m + (dp[i - 1][2] * 1ll * a[2]) % (m)) % (m);
            dp[i][2] = (((dp[i - 1][0] * 1ll * a[2]) % (m) + (dp[i - 1][1] * 1ll * a[1]) % (m)) % m + (dp[i - 1][2] * 1ll * a[0]) % (m)) % (m);
        }
    }
    cout << dp[n - 1][0];

    return 0;
}