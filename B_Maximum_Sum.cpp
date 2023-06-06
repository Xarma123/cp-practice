#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, k;
        cin >> n >> k;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        lol c[n];
        for (lol i = 0; i < n; i++)
        {
            if (i == 0)
                c[i] = a[i];
            else
                c[i] = c[i - 1] + a[i];
        }
        lol ans = LONG_LONG_MIN;
        for (lol i = 0; i <= k; i++)
        {
            lol l = i * 2ll - 1;
            lol r = n - 1 - (k - i);
            lol v = c[r];
            if (l >= 0)
                v -= c[l];
            ans = max(ans, v);
        }
        cout << ans << '\n';
    }
}