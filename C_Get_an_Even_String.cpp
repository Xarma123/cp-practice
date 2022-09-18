#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        map<char, lol> mp;
        lol dp[s.size() + 1];
        dp[0] = 0;
        for (lol i = 0; i < s.size(); i++)
        {
            dp[i + 1] = LONG_LONG_MIN;
            if (mp.count(s[i]))
            {
                dp[i + 1] = dp[mp[s[i]]] + 2;
            }
            dp[i + 1] = max(dp[i + 1], dp[i]);
            mp[s[i]] = i;
        }
        cout << s.size() - dp[s.size()] << endl;
    }

    return 0;
}