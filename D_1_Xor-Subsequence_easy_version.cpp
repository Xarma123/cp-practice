#include <bits/stdc++.h>
#define lol long long
using namespace std;
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
        
            lol dp[n];
            dp[0] = 1;
            lol ans = 1;
            for (lol i = 1; i < n; i++)
            {
                if (a[i] > 200)
                {
                    dp[i] = 0;
                }
                else
                {
                    dp[i] = 1;
                    for (lol j = i - 1; j >= 0; j--)
                    {
                        if (a[i] > a[j] && (a[j] <= 200))
                        {
                            if ((a[a[j]] ^ a[i]) < (a[a[i]] ^ a[j]))
                                dp[i] = max(dp[i], dp[j] + 1);
                        }
                    }
                }
                ans = max(ans, dp[i]);
            }
            cout << ans << endl;
        
       
    }

    return 0;
}