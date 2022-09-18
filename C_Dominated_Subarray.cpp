#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[n];
        map<lol, lol> mp;
        lol ans = LONG_LONG_MAX;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            if (mp.count(a[i]))
            {
                ans = min(ans, i - mp[a[i]] + 1);
            }
            mp[a[i]] = i;
        }
        if (ans == LONG_LONG_MAX)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }

    return 0;
}