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
        lol cn = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] < 0)
                cn++;
        }
        sort(a, a + n);
        lol ans = LONG_LONG_MIN;
        if (cn >= 4)
        {
            ans = a[0] * a[1] * a[2] * a[3] * a[n - 1];
        }
        if (cn >= 2)
        {
            ans = max(ans, a[0] * a[1] * a[n - 1] * a[n - 2] * a[n - 3]);
        }
        ans = max(ans, a[n - 1] * a[n - 2] * a[n - 3] * a[n - 4] * a[n - 5]);
        cout << ans << endl;
    }

    return 0;
}