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
        lol n, x, y;
        cin >> n >> x >> y;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        map<pair<lol, lol>, lol> mp;
        lol ans = 0;
        for (lol i = 0; i < n; i++)
        {
            lol r1 = (x - (a[i] % x)) % x;
            lol r2 = a[i] % y;
            ans += mp[{r1, r2}];
            mp[{(a[i] % x), (a[i] % y)}]++;
        }
        cout << ans << '\n';
    }

    return 0;
}
