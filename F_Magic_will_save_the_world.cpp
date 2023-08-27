#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol w, f;
        cin >> w >> f;
        lol n;
        cin >> n;
        lol sum = 0;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        bool dp[n][sum + 1];
        memset(dp, false, sizeof(dp));
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j <= sum; j++)
            {
                if (i == 0)
                {
                    if (j == a[i] || j == 0)
                        dp[i][j] = true;
                }
                else if (j == 0)
                {
                    dp[i][j] = true;
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                    if (j - a[i] >= 0)
                    {
                        dp[i][j] |= dp[i - 1][j - a[i]];
                    }
                }
            }
        }
        sort(a, a + n);
        lol e = (long long)ceill(sum / (long double)w) + 1000 + (long long)ceill(sum / (long double)f);
        lol s = 0;
        while (s != e - 1)
        {
            lol m = (s + e) / 2;
            lol W = w * 1ll * m;
            lol F = f * 1ll * m;
            for (lol i = sum; i >= 0; i--)
            {
                if (i <= F && dp[n - 1][i])
                {
                    if (W >= sum - i)
                    {
                        e = m;
                    }
                    else
                        s = m;
                    break;
                }
            }
        }
        cout << e << '\n';
    }
}