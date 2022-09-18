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
        lol c[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> c[i];
        }

        map<lol, lol> mp;
        map<lol, lol> mpod;
        map<lol, lol> mpev;

        lol dp[n];
        dp[0] = 1;
        mp[c[0]] = 1;
        mpev[c[0]] = 1;
        for (lol i = 1; i < n; i++)
        {
            dp[i] = 1;
            if (i % 2 == 0)
                dp[i] = max(dp[i], mpod[c[i]] + 1);
            else
                dp[i] = max(dp[i], mpev[c[i]] + 1);

            mp[c[i]] = max(mp[c[i]], dp[i]);
            if (i % 2 == 0)
                mpev[c[i]] = max(mpev[c[i]], dp[i]);
            else
                mpod[c[i]] = max(mpod[c[i]], dp[i]);
        }
        for (lol i = 1; i <= n; i++)
        {
            cout << mp[i] << " ";
        }
        cout << endl;
    }

    return 0;
}