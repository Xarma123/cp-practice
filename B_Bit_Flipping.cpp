#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        bool dp[n];
        lol ans[n];
        memset(dp, false, sizeof(dp));
        memset(ans, 0, sizeof(ans));
        for (lol i = 0; i < n; i++)
        {
            if (k % 2)
            {
                if (s[i] == '1')
                    dp[i] = true;
            }
            else
            {
                if (s[i] == '0')
                    dp[i] = true;
            }
        }
        if (k % 2)
        {
            for (lol i = 0; i < n; i++)
            {
                s[i] = char(1 - (s[i] - '0') + '0');
            }
        }
        for (lol i = 0; i < n; i++)
        {
            if (dp[i] && k > 0)
            {
                ans[i]++;
                k--;
                s[i] = '1';
            }
        }
        ans[n - 1] += k;
        if (k % 2)
        {
            s[n - 1] = '0';
        }
        cout << s << '\n';
        for (lol i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << '\n';
    }
}