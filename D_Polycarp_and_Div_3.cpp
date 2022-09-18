#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    string s;
    cin >> s;
    vector<lol> x;
    for (lol i = 0; i < s.size(); i++)
    {
        lol v = s[i] - '0';
        v = v % 3;
        x.push_back(v);
    }
    lol c[x.size() + 1];
    c[0] = 0;
    for (lol i = 1; i <= x.size(); i++)
    {
        c[i] = (c[i - 1] + x[i - 1]) % 3;
    }
    lol dp[x.size() + 1];
    dp[0] = 0;
    map<lol, lol> mp;
    mp[0] = 0;
    for (lol i = 1; i <= x.size(); i++)
    {
        dp[i] = dp[i - 1];
        if (mp.count(c[i]))
        {
            dp[i] = max(dp[i], dp[mp[c[i]]] + 1);
        }
        mp[c[i]] = i;
    }
    cout << dp[x.size()];

    return 0;
}