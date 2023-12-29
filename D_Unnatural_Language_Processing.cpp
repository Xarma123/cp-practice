#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
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
        bool dp[n + 1];
        memset(dp, false, sizeof(dp));
        dp[n] = true;
        for (lol i = n - 1; i >= 0; i--)
        {
            dp[i] = false;
            if (i + 1 < n)
            {
                if (s[i] != 'a' && s[i] != 'e' && (s[i + 1] == 'a' || s[i + 1] == 'e'))
                    dp[i] |= dp[i + 2];
            }
            if (i + 2 < n)
            {
                if (s[i] != 'a' && s[i] != 'e' && (s[i + 1] == 'a' || s[i + 1] == 'e') && s[i + 2] != 'a' && s[i + 2] != 'e')
                    dp[i] |= dp[i + 3];
            }
        }
        lol i = 0;
        while (i < n)
        {
            if (i + 2 <= n)
            {
                if (dp[i + 2])
                {
                    cout << s[i] << s[i + 1];
                    if (i + 2 != n)
                        cout << '.';
                    i = i + 2;
                    continue;
                }
            }
            if (i + 3 <= n)
            {
                if (dp[i + 3])
                {
                    cout << s[i] << s[i + 1] << s[i + 2];
                    if (i + 3 != n)
                        cout << '.';
                    i = i + 3;
                }
            }
        }
        cout << '\n';
    }

    return 0;
}
