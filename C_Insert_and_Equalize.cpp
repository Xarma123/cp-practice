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
        set<lol> x;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            x.insert(a[i]);
        }
        if (n == 1)
        {
            cout << 1 << '\n';
            continue;
        }
        sort(a, a + n);
        lol g = 0;
        for (lol i = 0; i < n; i++)
        {
            g = __gcd(g, a[n - 1] - a[i]);
        }

        lol ans = 0;
        for (lol i = 0; i < n; i++)
        {
            ans += (a[n - 1] - a[i]) / g;
        }
      
        lol c = a[n - 1];
        while (x.count(c))
        {
            c -= g;
        }
        lol c2 = a[n - 1];
        while (x.count(c2))
        {
            c2 += g;
        }
        ans += min(((a[n - 1] - c) / g), n * 1ll * ((c2 - a[n - 1]) / g));
        cout << ans << '\n';
    }

    return 0;
}
