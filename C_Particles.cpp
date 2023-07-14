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
        lol c[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> c[i];
        }
        if (n == 1)
        {
            cout << c[0] << '\n';
        }
        else if (n == 2)
        {
            cout << max(c[0], c[1]) << '\n';
        }
        else
        {
            lol dp[n];
            lol ans = c[0];
            dp[0] = c[0];
            lol mxod = 0;
            lol mxev = 0;
            for (lol i = 1; i < n; i++)
            {

                if (i % 2)
                {
                    if (i - 2 >= 0)
                        mxod = max(mxod, dp[i - 2]);
                    dp[i] = max(mxod + c[i], c[i]);
                }
                else
                {
                    if (i - 2 >= 0)
                        mxev = max(mxev, dp[i - 2]);
                    dp[i] = max(mxev + c[i], c[i]);
                }
                ans = max(ans, dp[i]);
            }

            if (ans == 0)
            {
                lol mx = -1e10;
                lol i;
                for (i = 0; i < n; i++)
                {
                    mx = max(mx, c[i]);
                    if (c[i] >= 0)
                        break;
                }
                if (i >= n)
                {
                    ans = mx;
                }
            }
            cout << ans << '\n';
        }
    }
}