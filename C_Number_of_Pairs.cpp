#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol T;
    cin >> T;
    while (T--)
    {
        lol n, l, r;
        cin >> n >> l >> r;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        lol ans = 0;
        for (lol i = 0; i < n; i++)
        {
            if (a[i] > r)
            {
                break;
            }
            else if (a[i] >= l && a[i] <= r)
            {
                lol other = r - a[i];
                lol j = upper_bound(a, a + i, other) - a;
                ans += j;
            }
            else
            {
                lol other = r - a[i];
                lol j = upper_bound(a, a + i, other) - a;
                lol k = lower_bound(a, a + i, (l - a[i])) - a;
                ans += j;
                ans -= k;
            }
        }
        cout << ans << endl;
    }

    return 0;
}