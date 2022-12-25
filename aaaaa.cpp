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
        string s;
        cin >> s;
        lol dp[s.size() + 1];
        dp[0] = 1e9;
        lol ans = 1e9;
        for (lol i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                dp[i + 1] = 0;
                ans = min(ans, dp[i] + 1);
            }
            else
                dp[i + 1] = dp[i] + 1;
            if (i - 1 >= 0 && dp[i - 1] == 0)
            {
                dp[i + 1] = 0;
            }
        }
        cout << ans << endl;
    }

    return 0;
}