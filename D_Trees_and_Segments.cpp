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
        lol n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        lol pr[n][k + 1];
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j <= k; j++)
            {
                if (i == 0)
                {
                    if (j == 0)
                    {
                        if (s[i] == '0')
                            pr[i][j] = 1;
                        else
                            pr[i][j] = 0;
                    }
                    else
                    {
                        pr[i][j] = 1;
                    }
                }
                else
                {

                    if (s[i] == '0')
                    {
                        pr[i][j] = pr[i - 1][j] + 1;
                    }
                    else
                    {
                        if (j)
                            pr[i][j] = pr[i - 1][j - 1] + 1;
                        else
                            pr[i][j] = 0;
                    }
                }
            }
        }
        for (lol i = 1; i < n; i++)
        {
            for (lol j = 0; j <= k; j++)
            {
                pr[i][j] = max(pr[i - 1][j], pr[i][j]);
            }
        }
        lol suf[n][k + 1];
        for (lol i = n - 1; i >= 0; i--)
        {
            for (lol j = 0; j <= k; j++)
            {
                if (i == n - 1)
                {
                    if (j == 0)
                    {
                        if (s[i] == '0')
                            suf[i][j] = 1;
                        else
                            suf[i][j] = 0;
                    }
                    else
                    {
                        suf[i][j] = 1;
                    }
                }
                else
                {

                    if (s[i] == '0')
                    {
                        suf[i][j] = suf[i + 1][j] + 1;
                    }
                    else
                    {
                        if (j)
                            suf[i][j] = suf[i + 1][j - 1] + 1;
                        else
                            suf[i][j] = 0;
                    }
                }
            }
        }
        for (lol i = n - 2; i >= 0; i--)
        {
            for (lol j = 0; j <= k; j++)
            {
                suf[i][j] = max(suf[i + 1][j], suf[i][j]);
            }
        }
        lol c[n];
        for (lol i = 0; i < n; i++)
        {
            if (s[i] == '0')
                c[i] = 1;
            else
                c[i] = 0;
            if (i)
                c[i] += c[i - 1];
        }
        lol dp[n + 1];
        for (lol l = 1; l <= n; l++)
        {
            dp[l] = LONG_LONG_MIN;
            for (lol i = 0, j = l - 1; j < n; i++, j++)
            {
                lol v = c[j];
                if (i - 1 >= 0)
                    v -= c[i - 1];
                if (v > k)
                    continue;
                dp[l] = max(dp[l], 0ll);
                if (i - 1 >= 0)
                {
                    dp[l] = max(dp[l], pr[i - 1][k - v]);
                }
                if (j + 1 < n)
                {
                    dp[l] = max(dp[l], suf[j + 1][k - v]);
                }
            }
        }
        dp[0] = pr[n - 1][k];
        for (lol a = 1; a <= n; a++)
        {
            lol mx = LONG_LONG_MIN;
            for (lol i = 0; i <= n; i++)
            {
                if (dp[i] != LONG_LONG_MIN)
                    mx = max(mx, i + a * 1ll * dp[i]);
            }
            cout << mx << " ";
        }
        cout << '\n';
    }
}