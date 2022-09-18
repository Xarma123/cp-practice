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
        lol mn = LONG_LONG_MAX;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            mn = min(mn, a[i]);
        }
        lol cnt = 0;
        for (lol i = 0; i < n; i++)
        {
            if (a[i] == mn)
            {
                cnt++;
            }
            if (a[i] & mn != mn)
            {
                cnt = -1;
                break;
            }
        }
        if (cnt < 2)
            cout << 0 << endl;
        else
        {
            lol mod = 1e9 + 7;
            lol fact = 1;
            for (lol i = 2; i <= n - 2; i++)
            {
                fact = (1ll * fact * (i)) % mod;
            }

            lol ans = (1ll * cnt * (cnt - 1)) % mod;
            ans = (1ll * ans * fact) % mod;
            cout << ans << endl;
        }
    }

    return 0;
}