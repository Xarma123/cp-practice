#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, p, k;
        cin >> n >> p >> k;
        string a;
        cin >> a;
        lol x, y;
        cin >> x >> y;
        lol dp[n];
        for (lol i = n - 1; i >= p - 1; i--)
        {
            if (i + k >= n)
            {
                if (a[i] == '0')
                    dp[i] = x;
                else
                    dp[i] = 0;
            }
            else
            {
                if (a[i] == '0')
                    dp[i] = x + dp[i + k];
                else
                    dp[i] = dp[i + k];
            }
        }
        lol ans = LONG_LONG_MAX;
        lol c = 0;
        for (lol i = p - 1; i < n; i++)
        {
            ans = min(ans, dp[i] + c);
            c += y;
        }
        cout << ans << endl;
    }

    return 0;
}