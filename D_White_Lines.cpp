#include <bits/stdc++.h>
using namespace std;
#define lol long long

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, k;
    cin >> n >> k;
    string a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    pair<lol, lol> c[n];
    for (lol j = 0; j < n; j++)
    {
        lol l = -1, r = -1;
        for (lol i = 0; i < n; i++)
        {
            if (a[i][j] == 'B')
            {
                if (l == -1)
                    l = i;
                r = i;
            }
        }
        c[j] = {l, r};
    }
    pair<lol, lol> rw[n];
    for (lol i = 0; i < n; i++)
    {
        lol l = -1, r = -1;
        for (lol j = 0; j < n; j++)
        {
            if (a[i][j] == 'B')
            {
                if (l == -1)
                    l = j;
                r = j;
            }
        }
        rw[i] = {l, r};
    }
    lol dp[n][n];
    memset(dp, 0, sizeof(dp));
    lol dp1[n][n];
    memset(dp1, 0, sizeof(dp1));
    for (lol i = 0; i < n; i++)
    {
        if (rw[i].first != -1)
        {
            lol l = rw[i].first;
            lol r = rw[i].second;
            if (r - l + 1 > k)
                continue;
            lol l1 = max(l - (k - (r - l + 1)), 0ll);
            // l1 - l
            for (lol j = i; j >= 0 && j + k - 1 >= i; j--)
            {
                dp[j][l]++;
                if (l1 - 1 >= 0)
                    dp[j][l1 - 1]--;
            }
        }
    }
    for (lol i = 0; i < n; i++)
    {
        for (lol j = n - 2; j >= 0; j--)
        {
            dp[i][j] += dp[i][j + 1];
        }
    }
    for (lol j = 0; j < n; j++)
    {
        if (c[j].first != -1)
        {

            lol l = c[j].first;
            lol r = c[j].second;
            if (r - l + 1 > k)
                continue;
            lol l1 = max(0ll, l - (k - (r - l + 1)));
            // l1-l

            for (lol i = j; i >= 0 && i + k - 1 >= j; i--)
            {
                dp1[l][i]++;
                if (l1 - 1 >= 0)
                    dp1[l1 - 1][i]--;
            }
        }
    }
    for (lol j = 0; j < n; j++)
    {
        for (lol i = n - 2; i >= 0; i--)
        {
            dp1[i][j] += dp1[i + 1][j];
        }
    }
    lol v = 0;
    for (lol i = 0; i < n; i++)
    {
        for (lol j = 0; j < n; j++)
        {
            v = max(v, dp[i][j] + dp1[i][j]);
        }
    }
    lol ans = 0;
    for (lol i = 0; i < n; i++)
    {
        if (rw[i].first == -1)
            ans++;
        if (c[i].first == -1)
            ans++;
    }

    cout << ans + v;
}