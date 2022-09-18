#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol q;
    cin >> q;
    while (q--)
    {
        lol n;
        cin >> n;
        pair<lol, lol> a[n];
        for (lol i = 0; i < n; i++)
        {
            lol x, y;
            cin >> x >> y;
            a[i] = {x, y};
        }
        lol dp[n][2];
        for (lol i = 0; i < n; i++)
        {
            dp[i][0] = 0;
            dp[i][1] = a[i].second;
            if (i - 1 >= 0)
            {
                lol v = LONG_LONG_MAX;
                if (a[i - 1].first != a[i].first)
                {
                    v = min(v, dp[i - 1][0]);
                }
                if (a[i - 1].first + 1 != a[i].first)
                {
                    v = min(v, dp[i - 1][1]);
                }
                dp[i][0] += v;
                v = LONG_LONG_MAX;
                if (a[i - 1].first != a[i].first + 1)
                {
                    v = min(v, dp[i - 1][0]);
                }
                if (a[i - 1].first + 1 != a[i].first + 1)
                {
                    v = min(v, dp[i - 1][1]);
                }
                dp[i][1] += v;
            }
        }
        cout << min(dp[n - 1][0], dp[n - 1][1]) << endl;
    }

    return 0;
}