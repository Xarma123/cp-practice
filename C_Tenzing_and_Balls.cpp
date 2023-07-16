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
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol dp[n + 1];
        for (lol i = 0; i <= n; i++)
        {
            dp[i] = LONG_LONG_MIN;
        }

        lol ans = 0;
        lol c = 0;
        for (lol i = 0; i < n; i++)
        {
            lol ans2 = max(dp[a[i]] + c + 1, ans);
            dp[a[i]] = max(dp[a[i]], ans - c);
            c++;
            ans = ans2;
        }
        cout << ans << '\n';
    }
}