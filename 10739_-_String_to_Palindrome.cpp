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
        lol c = 1;
        while (cin >> s)
        {
            cout << "Case " << c << ": ";
            lol dp[s.size()][s.size()];
            for (lol l = 0; l < s.size(); l++)
            {
                for (lol i = 0, j = l; j < s.size(); j++, i++)
                {
                    if (i == j)
                        dp[i][j] = 0;
                    else if (i == j - 1)
                    {
                        if (s[i] == s[j])
                            dp[i][j] = 0;
                        else
                            dp[i][j] = 1;
                    }
                    else
                    {
                        dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
                        if (s[i] == s[j])
                            dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
                        else
                            dp[i][j] = min(dp[i][j], dp[i + 1][j - 1] + 1);
                    }
                }
            }
            cout << dp[0][s.size() - 1] << endl;

            c++;
        }
    }

    return 0;
}