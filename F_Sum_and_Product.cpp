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
        lol n;
        cin >> n;
        lol a[n];
        map<lol, lol> mp;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            mp[a[i]]++;
        }
        lol q;
        cin >> q;
        while (q--)
        {
            lol x, y;
            cin >> x >> y;
            lol ans = 0;

            lol v = (x + sqrtl(x * 1ll * x - 4ll * y)) / 2ll;
            if ( v * 1ll * v - x * 1ll * v + y == 0)
            {
                if (y % v == 0)
                {
                    lol v2 = y / v;
                    if (v == v2)
                    {
                        ans += mp[v] * 1ll * (mp[v] - 1) / 2ll;
                    }
                    else
                        ans += mp[v] * 1ll * mp[v2];
                }
            }
            lol olv = v;
            v = (x - sqrtl(x * 1ll * x - 4ll * y)) / 2ll;
            if (v != olv  && v * 1ll * v - x * 1ll * v + y == 0)
            {
                if (y % v == 0)
                {
                    lol v2 = y / v;
                    if (v == v2)
                    {
                        ans += mp[v] * 1ll * (mp[v] - 1) / 2ll;
                    }
                    else if (v2 != olv)
                        ans += mp[v] * 1ll * mp[v2];
                }
            }
            cout << ans << " ";
        }
        cout << '\n';
    }
}