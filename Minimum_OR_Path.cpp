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
        lol a[n];
        lol dp[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            dp[i] = LONG_LONG_MAX;
        }

        dp[0] = 0;
        vector<lol> c[n];
        for (lol i = 0; i < n; i++)
        {
            c[i].clear();
        }

        lol j = min(a[0], n - 1);
        if (j + 1 < n)
            c[j + 1].push_back(dp[0]);
        map<lol, lol> mp;
        mp[dp[0]]++;
        for (lol i = 1; i < n; i++)
        {
            for (auto e : c[i])
            {
                mp[e]--;
                if (mp[e] == 0)
                    mp.erase(e);
            }
            if (mp.size())
                dp[i] = (((((a[i] | a[n - 1]) ^ a[n - 1]) | a[0]) ^ a[0]) | ((*mp.begin()).first));
            mp[dp[i]]++;
            lol j = min(i + a[i], n - 1);
            if (j + 1 < n)
                c[j + 1].push_back(dp[i]);
        }
        if (dp[n - 1] == LONG_LONG_MAX)
            dp[n - 1] = -1;
        else
            dp[n - 1] |= a[n - 1] | a[0];
        cout << dp[n - 1] << '\n';
    }

    return 0;
}