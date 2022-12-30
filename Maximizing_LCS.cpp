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

        lol dp[s.size()][s.size()];
        lol mx = 0;
        for (lol len = 0; len < s.size(); len++)
        {
            for (lol i = 0, j = len; j < s.size(); j++, i++)
            {
                if (i == j)
                {
                    dp[i][j] = 1;
                }
                else if (i == j - 1)
                {
                    if (s[i] == s[j])
                        dp[i][j] = 2;
                    else
                        dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                    if (s[i] == s[j])
                        dp[i][j] = max(dp[i][j], 2 + dp[i + 1][j - 1]);
                }
                mx = max(mx, dp[i][j]);
            }
        }
        cout << mx / 2 << endl;
    }

    return 0;
}