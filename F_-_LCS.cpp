#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s, t;
    cin >> s >> t;
    lol dp[s.size() + 1][t.size() + 1];
    for (lol i = 0; i <= s.size(); i++)
    {
        for (lol j = 0; j <= t.size(); j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                if (s[i - 1] == t[j - 1])
                    dp[i][j] = max(dp[i][j], 1 + dp[i - 1][j - 1]);
            }
        }
    }
    string ans = "";
    lol i = s.size(), j = t.size();
    while (i > 0 && j > 0)
    {
        if (s[i - 1] == t[j - 1])
        {
            if (dp[i - 1][j - 1] + 1 >= dp[i - 1][j] && dp[i - 1][j - 1] + 1 >= dp[i][j - 1])
            {
                ans.push_back(s[i - 1]);
                i--;
                j--;
                continue;
            }
        }
        if (dp[i - 1][j] >= dp[i][j - 1])
            i--;
        else
            j--;
    }
    reverse(ans.begin(), ans.end());

    cout << ans;

    return 0;
}