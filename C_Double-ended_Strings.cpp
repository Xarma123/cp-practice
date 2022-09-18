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
        string a, b;
        cin >> a >> b;
        lol dp[a.size() + 1][b.size() + 1];
        for (lol i = 0; i <= a.size(); i++)
        {
            dp[i][0] = 0;
        }
        for (lol i = 0; i <= b.size(); i++)
        {
            dp[0][i] = 0;
        }
        lol ans = 0;
        for (lol i = 1; i <= a.size(); i++)
        {
            for (lol j = 1; j <= b.size(); j++)
            {
                if (a[i - 1] == b[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                    dp[i][j] = 0;
                ans = max(ans, dp[i][j]);
            }
        }
        cout << a.size() - ans + b.size() - ans << endl;
    }

    return 0;
}