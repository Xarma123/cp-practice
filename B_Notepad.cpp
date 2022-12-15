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
        bool dp[26][26];
        memset(dp, false, sizeof(dp));
        bool ans = false;
        for (lol i = 0; i < n - 1; i++)
        {
            if (dp[s[i] - 'a'][s[i + 1] - 'a'])
            {
                ans = true;
            }
            if (i)
            {
                dp[s[i-1] - 'a'][s[i] - 'a'] = true;
            }
        }
        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}