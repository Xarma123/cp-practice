#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    bool dp[s.size()][s.size()];
    lol ans = 0;
    for (lol len = 0; len < s.size(); len++)
    {
        for (lol i = 0, j = len; j < s.size(); i++, j++)
        {
            if (j - i < 3)
            {
                dp[i][j] = false;
            }
            else if (j - i == 3)
            {
                if (s.substr(i, j - i + 1) == "bear")
                {

                    dp[i][j] = true;
                    ans++;
                }
                else
                    dp[i][j] = false;
            }
            else
            {
                if (dp[i + 1][j] || dp[i][j - 1])
                {

                    dp[i][j] = true;
                    ans++;
                }
                else
                    dp[i][j] = false;
            }
        }
    }
    cout << ans;

    return 0;
}