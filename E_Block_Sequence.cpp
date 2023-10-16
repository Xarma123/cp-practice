#include <bits/stdc++.h>
using namespace std;
#define lol long long
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
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol mx = 0;
        lol dp[n];
        lol c[n];
        for (lol i = 0; i < n; i++)
        {
            c[i] = LONG_LONG_MAX;
        }

        for (lol i = 0; i < n; i++)
        {
            mx = min(mx, c[i]);
            dp[i] = mx;
            if (i + a[i] + 1 < n)
                c[i + a[i] + 1] = min(c[i + a[i] + 1], dp[i]);
            mx++;
        }
        lol ans = LONG_LONG_MAX;
        for (lol i = 0; i < n; i++)
        {
            if (i + a[i] >= n)
                continue;
            ans = min(n - 1 - (i + a[i]) + dp[i], ans);
        }
        ans = min(ans, n);
        cout << ans << '\n';
    }
}