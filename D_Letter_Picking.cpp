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
        for (lol l = 1; l < s.size(); l += 2)
        {
            for (lol i = 0, j = l; j < s.size(); i++, j++)
            {
                if (i == j - 1)
                {
                    if (s[i] == s[j])
                        dp[i][j] = 0;
                    else
                        dp[i][j] = 1;
                }
                else
                {
                    // l
                    lol d1;
                    if (dp[i + 1][j - 1] == 2 || dp[i + 2][j] == 2)
                        d1 = 2;
                    else if (dp[i + 1][j - 1] == 1 && dp[i + 2][j] == 1)
                        d1 = 1;
                    else if (dp[i + 1][j - 1] == 0 && s[j] < s[i])
                        d1 = 2;
                    else if (dp[i + 2][j] == 0 && s[i + 1] < s[i])
                        d1 = 2;
                    else if (dp[i + 1][j - 1] == 0 && s[j] == s[i])
                        d1 = 0;
                    else if (dp[i + 2][j] == 0 && s[i + 1] == s[i])
                        d1 = 0;
                    else
                        d1 = 1;

                    // r
                    lol d2;
                    if (dp[i][j - 1] == 2 || dp[i][j - 2] == 2)
                        d2 = 2;
                    else if (dp[i + 1][j - 1] == 1 && dp[i][j - 2] == 1)
                        d2 = 1;
                    else if (dp[i + 1][j - 1] == 0 && s[i] < s[j])
                        d2 = 2;
                    else if (dp[i][j - 2] == 0 && s[j - 1] < s[j])
                        d2 = 2;
                    else if (dp[i + 1][j - 1] == 0 && s[i] == s[j])
                        d2 = 0;
                    else if (dp[i][j - 2] == 0 && s[j - 1] == s[j])
                        d2 = 0;
                    else
                        d2 = 1;
                    if (d1 == 1 || d2 == 1)
                        dp[i][j] = 1;
                    else if (d1 == 0 || d2 == 0)
                        dp[i][j] = 0;
                    else
                        dp[i][j] = 2;
                }
            }
        }
        if (dp[0][s.size() - 1] == 1)
            cout << "Alice\n";
        else if (dp[0][s.size() - 1] == 0)
            cout << "Draw\n";
        else
            cout << "Bob\n";
    }

    return 0;
}