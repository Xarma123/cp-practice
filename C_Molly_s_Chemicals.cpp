#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, k;
    cin >> n >> k;
    lol a[n];
    lol cs = 0;
    map<lol, lol> mp;
    mp[0]++;
    lol mn = 0, mx = 0;
    lol mxs = 0, mns = 0;
    lol ans = 0;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        cs += a[i];

        mxs = max(mxs, cs - mn);
        mns = min(mns, cs - mx);
        if (k > 0)
        {
            lol v = 1;
            while (v <= mxs)
            {
                ans += mp[cs - v];
                v = v * 1ll * k;
                if (v == 1)
                    break;
            }
        }
        else
        {
            lol v = 1;
            while (v <= mxs)
            {
                ans += mp[cs - v];
                v = v * 1ll * k * 1ll * k;
                if (v == 1)
                    break;
            }
             v = k;
            while (mns <= v)
            {
                ans += mp[cs - v];
                v = v * 1ll * k * 1ll * k;
                if (v == -1)
                    break;
            }
        }

        mp[cs]++;
        mn = min(mn, cs);
        mx = max(mx, cs);
    }
    cout << ans;

    return 0;
}