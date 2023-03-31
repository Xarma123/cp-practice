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
        lol n, x, y;
        cin >> n >> x >> y;
        string a, b;
        cin >> a >> b;
        vector<lol> v;
        for (lol i = 0; i < n; i++)
        {
            if (a[i] != b[i])
            {
                v.push_back(i);
            }
        }
        if (v.size() % 2)
            cout << -1 << '\n';
        else if (v.size() == 2)
        {
            if (v[0] == v[1] - 1)
                cout << min(x, 2ll * y) << '\n';
            else
                cout << min((v[1] - v[0]) * 1ll * x, y) << '\n';
        }
        else
        {
            lol dp[v.size() + 1];
            dp[0] = 0;
            dp[1] = 0;
            for (lol i = 2; i <= v.size(); i++)
            {
                if ((i % 2))
                {
                    dp[i] = min(dp[i - 2] + (v[i - 1] - v[i - 2]) * 1ll * x, dp[i - 1]);
                }
                else
                {
                    dp[i] = min(dp[i - 2] + (v[i - 1] - v[i - 2]) * 1ll * x, dp[i - 1] + y);
                }
            }
            cout << dp[v.size()] << '\n';
        }
    }

    return 0;
}