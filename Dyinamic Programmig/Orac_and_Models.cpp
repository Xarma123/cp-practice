#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol ans(lol arr[], lol n)
{
    lol dp[n];
    dp[0] = 1;
    lol ans = 1;
    for (lol i = 1; i < n; i++)
    {
        dp[i] = 1;
        for (lol j = 1; j <= sqrt(i + 1); j++)
        {
            
                if ((i + 1) % j == 0)
                {
                    if ((i + 1) / j == j)
                    {
                        if ((arr[j - 1] < arr[i]))
                        {

                            dp[i] = max(dp[i], dp[j - 1] + 1);
                        }
                    }
                    else
                    {
                        if ((arr[j - 1] < arr[i]))
                        {

                            dp[i] = max(dp[i], dp[j - 1] + 1);
                        }
                        if ((arr[((i + 1) / j) - 1] < arr[i]))
                        {

                            dp[i] = max(dp[i], dp[((i + 1) / j) - 1] + 1);
                        }
                    }
                }
            
        }

        ans = max(ans, dp[i]);
    }

    return ans;
}
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
        cout << ans(a, n) << endl;
    }

    return 0;
}