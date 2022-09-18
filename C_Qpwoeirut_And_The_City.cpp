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
        lol n;
        cin >> n;
        lol h[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> h[i];
        }
        lol cost1 = 0;
        for (lol i = 1; i < n - 1; i += 2)
        {
            lol q = 0;
            if (h[i - 1] >= h[i])
            {
                q = h[i - 1] - h[i] + 1;
            }
            if (h[i + 1] >= h[i])
            {
                q = max(q, h[i + 1] - h[i] + 1);
            }
            cost1 += q;
        }
        if (n % 2 != 0)
            cout << cost1 << endl;
        else
        {
            pair<lol, lol> dp[n];
            dp[0] = {0, 0};
            for (lol i = 1; i < n; i++)
            {
                // making it peak
                dp[i] = dp[i - 1];
                if (i + 1 < n)
                {
                    lol q = 0;
                    if (h[i - 1] >= h[i])
                    {
                        q = h[i - 1] - h[i] + 1;
                    }
                    if (h[i + 1] >= h[i])
                    {
                        q = max(q, h[i + 1] - h[i] + 1);
                    }
                    lol c = 1;
                    if (i - 2 >= 0)
                    {
                        c += dp[i - 2].first;
                        q += dp[i - 2].second;
                    }
                    dp[i] = {c, q};
                }

                // doing nothing
                if (dp[i - 1].first > dp[i].first)
                {
                    dp[i] = dp[i - 1];
                }
                else if (dp[i - 1].first == dp[i].first)
                {
                    dp[i].second = min(dp[i].second, dp[i - 1].second);
                }
            }
            cout << dp[n-1].second << endl;
        }
    }

    return 0;
}