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
        string s;
        cin >> s;
        lol n = s.size();
        lol dp[n + 1][26];
        for (lol i = n; i >= 0; i--)
        {
            if (i == n)
            {
                for (lol j = 0; j < 26; j++)
                {
                    dp[i][j] = n + 1;
                }
            }
            else
            {
                for (lol j = 0; j < 26; j++)
                {
                    dp[i][j] = dp[i + 1][j];
                }
                dp[i][s[i] - 'a'] = i + 1;
            }
        }
        lol ans = 0;
        string b;
        cin >> b;
        for (lol i = 0; i < b.size(); i++)
        {
            lol j = i;
            lol p = 0;
            ans++;
            while (j < b.size() && dp[p][b[j] - 'a'] != n + 1)
            {
                p = dp[p][b[j] - 'a'];
                j++;
            }
            if (j == i)
            {
                ans = -1;
                break;
            }
            i = j - 1;
        }
        cout << ans << '\n';
    }
}