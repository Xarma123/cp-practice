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
    for (lol qqqw = 1; qqqw <= t; qqqw++)
    {
        cout << "Case #" << qqqw << ": ";
        string s;
        cin >> s;
        lol ans = LONG_LONG_MAX;
        char f[3] = {'P', 'R', 'S'};
        for (lol j = 0; j < 3; j++)
        {
            lol dp[s.size()][3];
            for (lol i = 1; i < s.size(); i++)
            {
                if (i == 1)
                {
                    dp[i][0] = (s[i] != f[0]);
                    dp[i][1] = (s[i] != f[1]);
                    dp[i][2] = (s[i] != f[2]);
                    dp[i][j] = 1e10;
                }
                else
                {
                    dp[i][0] = (s[i] != f[0]);
                    dp[i][1] = (s[i] != f[1]);
                    dp[i][2] = (s[i] != f[2]);
                    dp[i][0] += min(dp[i - 1][1], dp[i - 1][2]);
                    dp[i][1] += min(dp[i - 1][0], dp[i - 1][2]);
                    dp[i][2] += min(dp[i - 1][1], dp[i - 1][0]);
                }
            }
            dp[s.size() - 1][j] = 1e10;
            ans = min(ans, min(dp[s.size() - 1][1], min(dp[s.size() - 1][0], dp[s.size() - 1][2])) + (s[0] != f[j]));
        }
        cout << ans << '\n';
    }

    return 0;
}