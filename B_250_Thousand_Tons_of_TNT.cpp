#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol ans = 0;
        for (lol k = 1; k * 1ll * k <= n; k++)
        {
            if (n % k == 0)
            {
                unordered_map<lol, lol> mp;
                for (lol i = 0; i < n; i++)
                {
                    mp[i / k] += a[i];
                }
                lol mx = 0, mn = LONG_LONG_MAX;
                for (auto e : mp)
                {
                    mx = max(mx, e.second);
                    mn = min(mn, e.second);
                }
                ans = max(ans, mx - mn);
                k = n / k;
                mp.clear();
                for (lol i = 0; i < n; i++)
                {
                    mp[i / k] += a[i];
                }
                mx = 0, mn = LONG_LONG_MAX;
                for (auto e : mp)
                {
                    mx = max(mx, e.second);
                    mn = min(mn, e.second);
                }
                ans = max(ans, mx - mn);
                k = n / k;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
