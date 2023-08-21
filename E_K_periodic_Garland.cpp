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
        lol n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        lol dp[n][2];
        lol c[n];
        for (lol i = 0; i < n; i++)
        {
            c[i] = s[i] - '0';
            if (i)
                c[i] += c[i - 1];
        }
        for (lol i = 0; i < n; i++)
        {
            if (s[i] == '0')
                dp[i][0] = 0;
            else
                dp[i][0] = 1;
            if (i)
                dp[i][0] += min(dp[i - 1][0], dp[i - 1][1]);
            if (s[i] == '1')
                dp[i][1] = 0;
            else
                dp[i][1] = 1;
            lol ex = 0;
            if (i - 1 >= 0)
                ex = c[i - 1];
            if (i - k >= 0)
            {
                ex = min(ex, dp[i - k][1] + c[i - 1] - c[i - k]);
            }
            dp[i][1] += ex;
        }
        cout << min(dp[n - 1][0], dp[n - 1][1]) << '\n';
    }
}