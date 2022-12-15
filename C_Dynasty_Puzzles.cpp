#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    string s[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    lol dp[26][26];
    lol oldp[26][26];
    for (lol i = 0; i < 26; i++)
    {
        for (lol j = 0; j < 26; j++)
        {
            dp[i][j] = LONG_LONG_MIN;
            oldp[i][j] = LONG_LONG_MIN;
        }
    }
    for (lol i = n - 1; i >= 0; i--)
    {
        dp[s[i][0] - 'a'][s[i].back() - 'a'] = max((long long)s[i].size(), dp[s[i][0] - 'a'][s[i].back() - 'a']);
        if (i != n - 1)
        {
            for (lol k = 0; k < 26; k++)
            {
                dp[s[i][0] - 'a'][k] = max(dp[s[i][0] - 'a'][k], oldp[s[i].back() - 'a'][k] + s[i].size());
            }
        }
        for (lol k = 0; k < 26; k++)
        {
            oldp[s[i][0] - 'a'][k] = dp[s[i][0] - 'a'][k];
        }
    }
    // for (lol i = n - 1; i >= 0; i--)
    // {

    //     for (lol j = 0; j < 26; j++)
    //     {
    //         for (lol k = 0; k < 26; k++)
    //         {
    //             cout << dp[j][k][i] << " ";
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }
    lol ans = 0;
    for (lol i = 0; i < 26; i++)
    {
        ans = max(ans, dp[i][i]);
    }

    cout << ans;

    return 0;
}