#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n, m;
    cin >> n >> m;
    map<lol, lol> mp;
    lol b[n];
    lol ans = 0;
    lol mx = LONG_LONG_MIN;
    for (lol i = 0; i < n; i++)
    {
        lol q;
        cin >> q;
        b[i] = q;
        mp[q]++;
        ans += q;
        mx = max(mx, q);
    }
    lol mn = LONG_LONG_MAX;
    lol g[m];
    for (lol i = 0; i < m; i++)
    {

        cin >> g[i];

        ans += g[i];
        mn = min(mn, g[i]);
    }
    if (mx > mn)
        cout << -1;
    else
    {
        lol c = 0;
        for (lol i = 0; i < m; i++)
        {
            if (mp.count(g[i]))
            {
                ans -= g[i];
                mp[g[i]]--;
                if (mp[g[i]] == 0)
                    mp.erase(g[i]);
            }
            else
                c++;
        }
        sort(b, b + n);
        for (lol i = n - 1; i >= 0; i--)
        {
            lol v = m - 1;
            while (v > 0 && c > 0)
            {
                v--;
                c--;
            }
            while (v--)
            {
                ans += b[i];
            }
        }
        cout << ans;
    }

    return 0;
}