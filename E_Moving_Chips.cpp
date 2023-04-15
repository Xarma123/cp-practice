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
        string a[2];
        cin >> a[0] >> a[1];
        lol dp[2][n];
        bool f = true;
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < 2; j++)
            {
                if (f)
                {
                    if (a[1 - j][i] == '*')
                        dp[j][i] = 1;
                    else
                        dp[j][i] = 0;
                }
                else
                {
                    if (a[1 - j][i] == '*')
                    {
                        dp[j][i] = 2 + min(dp[j][i - 1], dp[1 - j][i - 1]);
                    }
                    else
                    {
                        dp[j][i] = min(dp[j][i - 1] + 1, 2 + dp[1 - j][i - 1]);
                    }
                }
               
            }
         
            if (a[0][i] == '*' || a[1][i] == '*')
                f = false;
        }
        lol i;
        for (i = n - 1; i >= 0; i--)
        {
            if (a[0][i] == '*' || a[1][i] == '*')
            {

                break;
            }
        }
        cout << min(dp[0][i], dp[1][i]) << '\n';
    }

    return 0;
}