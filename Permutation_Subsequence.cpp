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
        lol m = 1e9 + 7;
        map<lol, lol> mp;
        for (lol i = 0; i < n; i++)
        {
            lol v;
            cin >> v;
            mp[v]++;
            mp[v] %= m;
        }
        lol ans = 0;
        lol til = 1;
        for (lol i = 1; i <= n; i++)
        {
            if (mp.count(i))
            {
                til = (til * 1ll * mp[i]) % m;
                ans += til;
                ans %= m;
            }
            else
                break;
        }

        cout << ans << '\n';
    }

    return 0;
}