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
        string s;
        cin >> s;
        lol dp[s.size()][s.size()];
        for (lol k = 0; k < s.size(); k++)
        {
            for (lol i = 0, j = k; j < s.size(); i++, j++)
            {
                if (i == j)
                {
                    dp[i][j] = 1;
                }
                else if (i == j - 1)
                {
                    dp[i][j] = 2;
                    if (s[i] == s[j])
                        dp[i][j]++;
                }
                else
                {
                    dp[i][j] = 0;
                    if (s[i] == s[j])
                        dp[i][j] += dp[i + 1][j - 1] + 1;
                    dp[i][j] += dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1];
                }
            }
        }
        cout << dp[0][s.size() - 1] << endl;
    }

    return 0;
}