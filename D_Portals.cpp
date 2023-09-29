#include <bits/stdc++.h>
using namespace std;
#define lol long long

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m, k;
    cin >> n >> m >> k;
    lol K = k;
    lol a[n], b[n], c[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
    }
    lol baldev[n];
    for (lol i = 0; i < n; i++)
    {
        baldev[i] = i;
    }

    while (m--)
    {
        lol u, v;
        cin >> u >> v;
        u--;
        v--;
        baldev[v] = max(baldev[v], u);
    }
    vector<lol> s[n];
    for (lol i = 0; i < n; i++)
    {
        s[baldev[i]].push_back(c[i]);
        if (k < a[i])
        {
            k = -1;
            break;
        }
        else
        {
            k += b[i];
        }
    }
    for (lol i = 0; i < n; i++)
    {
        sort(s[i].rbegin(), s[i].rend());
    }

    if (k == -1)
        cout << -1;
    else
    {
        k = K;
        lol dp[n][n + 1];
        for (lol i = 0; i < n; i++)
        {
            if (i == 0)
            {
                dp[i][0] = 0;
                lol v = 0;
                for (lol j = 1; j <= n; j++)
                {
                    if (j > s[i].size())
                    {
                        dp[i][j] = LONG_LONG_MIN;
                    }
                    else if (k + b[i] >= j)
                    {
                        v += s[i][j - 1];
                        dp[i][j] = v;
                    }
                    else
                        dp[i][j] = LONG_LONG_MIN;
                }
                k += b[i];
            }
            else
            {
                for (lol j = 0; j <= n; j++)
                {
                    dp[i][j] = LONG_LONG_MIN;
                }
                lol v = 0;
                for (lol j = 0; j <= s[i].size(); j++)
                {
                    for (lol l = 0; l + j <= n; l++)
                    {
                        if (k - l >= a[i] && k - l + b[i] >= j)
                        {
                            dp[i][l + j] = max(dp[i][l + j], dp[i - 1][l] + v);
                        }
                    }
                    if (j < s[i].size())
                        v += s[i][j];
                }
                k += b[i];
            }
        }
        lol ans = LONG_LONG_MIN;
        for (lol i = 0; i <= n; i++)
        {
            ans = max(ans, dp[n - 1][i]);
        }
        cout << ans << '\n';
    }
}