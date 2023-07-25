#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[n];
        lol ans = 1;
        lol c = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] <= 0)
                c++;
        }
        if (c > 0 && n - c > 0)
        {
            ans = max(ans, 2ll);
        }
        ans = max(ans, c);
        sort(a, a + n);
        lol mn = LONG_LONG_MAX;
        lol i;
        for (i = 1; i < n && a[i] <= 0; i++)
        {
            mn = min(mn, a[i] - a[i - 1]);
        }

        if (i < n && a[i] <= mn)
        {
            ans = max(ans, c + 1);
        }

        cout << ans << '\n';
    }
}
