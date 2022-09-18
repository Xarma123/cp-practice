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
        map<lol, lol> mp;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            mp[a[i]]++;
        }
        lol f = LONG_LONG_MIN;
        for (auto i = mp.begin(); i != mp.end(); i++)
        {
            f = max(f, (*i).second);
        }
        if (f == n)
            cout << 0 << endl;
        else
        {
            lol x = floorl(log2l((long double)n / (long double)f));
            lol v = n - powl(2, x) * 1ll * f;
            lol ans = x + f * 1ll * (powl(2, x) - 1);
            if (v > 0)
                ans += v + 1;
            cout << ans << endl;
        }
    }

    return 0;
}