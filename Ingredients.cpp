#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    lol dp[n][n];
    for (lol i = 0; i < n; i++)
    {
        for (lol j = 0; j < n; j++)
        {
            dp[i][j] = LONG_LONG_MAX;
        }
        dp[i][i] = 0;
    }
    while (m--)
    {
        lol a, b, c;
        cin >> a >> b >> c;
        dp[a][b] = min(dp[a][b], c);
        dp[b][a] = min(dp[b][a], c);
    }
    for (lol k = 0; k < n; k++)
    {
        for (lol j = 0; j < n; j++)
        {
            for (lol i = 0; i < n; i++)
            {
                if (dp[i][k] != LONG_LONG_MAX && dp[k][j] != LONG_LONG_MAX)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    lol s;
    cin >> s;
    vector<lol> w;
    while (s--)
    {
        lol a;
        cin >> a;
        w.push_back(a);
    }
    lol s1, s2;
    cin >> s1 >> s2;
    w.push_back(s1);
    lol k = w.size();
    lol dp1[(1ll << k)][k];
    for (lol i = 0; i < (1ll << k); i++)
    {
        for (lol j = 0; j < k; j++)
        {
            if (__builtin_popcount(i) == 0)
            {
                dp1[i][j] = 0;
            }
            else if (__builtin_popcount(i) == 1)
            {
                if (j == k - 1)
                    dp1[i][j] = 0;
                else
                    dp1[i][j] = LONG_LONG_MAX;
            }
            else if ((i & (1ll << j)) == 0)
                dp1[i][j] = LONG_LONG_MAX;
            else
            {
                dp1[i][j] = LONG_LONG_MAX;
                for (lol q = 0; q < k; q++)
                {
                    if (q != j && (i & (1ll << q)) && dp1[i ^ (1ll << j)][q] != LONG_LONG_MAX && dp[w[q]][w[j]] != LONG_LONG_MAX)
                    {
                        dp1[i][j] = min(dp1[i][j], dp1[i ^ (1ll << j)][q] + dp[w[q]][w[j]]);
                    }
                }
            }
        }
    }
    w.pop_back();
    w.push_back(s2);
    lol dp2[(1ll << k)][k];
    for (lol i = 0; i < (1ll << k); i++)
    {
        for (lol j = 0; j < k; j++)
        {
            if (__builtin_popcount(i) == 0)
            {
                dp2[i][j] = 0;
            }
            else if (__builtin_popcount(i) == 1)
            {
                if (j == k - 1)
                    dp2[i][j] = 0;
                else
                    dp2[i][j] = LONG_LONG_MAX;
            }
            else if ((i & (1ll << j)) == 0)
                dp2[i][j] = LONG_LONG_MAX;
            else
            {
                dp2[i][j] = LONG_LONG_MAX;
                for (lol q = 0; q < k; q++)
                {
                    if (q != j && (i & (1ll << q)) && dp2[i ^ (1ll << j)][q] != LONG_LONG_MAX && dp[w[q]][w[j]] != LONG_LONG_MAX)
                    {
                        dp2[i][j] = min(dp2[i][j], dp2[i ^ (1ll << j)][q] + dp[w[q]][w[j]]);
                    }
                }
            }
        }
    }
    lol ans = LONG_LONG_MAX;
    for (lol i = 0; i < (1ll << k); i++)
    {
        if (!(i & (1ll << (k - 1))))
        {
            continue;
        }
        lol i2 = (i ^ ((1ll << k) - 1));
        i2 |= (1ll << (k - 1));
        lol mn1 = LONG_LONG_MAX;
        lol mn2 = LONG_LONG_MAX;
        for (lol j = 0; j < k; j++)
        {
            mn1 = min(mn1, dp1[i][j]);
            mn2 = min(mn2, dp2[i2][j]);
        }
        if (mn1 != LONG_LONG_MAX && mn2 != LONG_LONG_MAX)
            ans = min(ans, mn1 + mn2);
    }
    cout << ans;

    return 0;
}
