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
        lol n, q;
        cin >> n >> q;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol dp[n][2];
        lol ans = 0;
        lol mx = 0;
        lol mx2 = 0;
        for (lol i = n - 1; i >= 0; i--)
        {
            dp[i][0] = a[i] + mx;
            dp[i][1] = -a[i] + mx2;
            mx = max(mx, dp[i][1]);
            mx2 = max(mx2, dp[i][0]);
            ans = max(ans, dp[i][0]);
        }
        cout << ans << '\n';
    }
}