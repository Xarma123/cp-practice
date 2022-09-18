#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, x;
        cin >> n >> x;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);

        lol dp[n];
        for (lol i = 0; i < n; i++)
        {
            dp[i] = 0;
        }

        for (lol i = n - 1; i >= 0; i--)
        {

            lol c = ceil(x / (long double)a[i]);
            if (i + c < n)
            {
                dp[i] = 1 + dp[i + c];
            }
            else if (i + c - 1 < n)
            {
                dp[i]++;
            }
        }
        lol ans = LONG_LONG_MIN;
        for (lol i = 0; i < n; i++)
        {
            ans = max(ans, dp[i]);
        }
        cout << ans << endl;
    }

    return 0;
}