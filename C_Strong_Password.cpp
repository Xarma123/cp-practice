#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        lol m;
        cin >> m;
        string l, r;
        cin >> l >> r;
        lol dp[10][s.size()];
        for (lol i = s.size() - 1; i >= 0; i--)
        {
            if (i == s.size() - 1)
            {
                for (lol j = 0; j < 10; j++)
                {
                    dp[j][i] = LONG_LONG_MAX;
                }
                dp[s[i] - '0'][i] = i;
            }
            else
            {
                for (lol j = 0; j < 10; j++)
                {
                    dp[j][i] = LONG_LONG_MAX;
                }
                dp[s[i] - '0'][i] = i;
                for (lol j = 0; j < 10; j++)
                {
                    dp[j][i] = min(dp[j][i], dp[j][i + 1]);
                }
            }
        }
        lol st = -1;
        for (lol i = 0; i < m; i++)
        {
            if (st + 1 >= s.size())
            {
                st = s.size();
                break;
            }
            lol mx = -1;
            for (lol j = l[i] - '0'; j <= r[i] - '0'; j++)
            {
                mx = max(mx, dp[j][st + 1]);
            }
            if (mx >= s.size())
            {
                st = mx;
                break;
            }
            st = mx;
        }
        if (st < s.size())
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}