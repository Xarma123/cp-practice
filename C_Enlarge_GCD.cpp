#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol a[n];
    lol mx = LONG_LONG_MIN;
    lol gcd = 0;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        mx = max(mx, a[i]);
        gcd = __gcd(a[i], gcd);
    }
    lol p[mx + 1];
    for (lol i = 0; i <= mx; i++)
    {
        p[i] = 1;
    }

    for (lol i = 2; i <= mx; i++)
    {
        if (p[i] == 1)
        {
            p[i] = i;
            for (lol j = i * 1ll * i; j <= mx; j += i)
            {
                p[j] = i;
            }
        }
    }
    map<lol, lol> f;
    lol ans = -1;
    for (lol i = 0; i < n; i++)
    {
        a[i] /= gcd;
        set<lol> us;
        while (a[i] > 1)
        {
            if (!us.count(p[a[i]]))
            {
                f[p[a[i]]]++;
                ans = max(ans, f[p[a[i]]]);
                us.insert(p[a[i]]);
            }

            a[i] /= p[a[i]];
        }

        us.clear();
    }
    if (ans == -1)
        cout << ans;
    else
        cout << n - ans;

    return 0;
}