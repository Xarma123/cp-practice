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
    vector<lol> q;
    map<lol, lol> mp;
    for (lol i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        lol j = 0;
        for (auto c : s)
        {
            lol v = c - '0';
            j |= (1ll << v);
        }
        mp[j]++;
    }
    lol ans = 0;
    for (lol i = 0; i < (1ll << 10); i++)
    {
        ans += mp[i] * 1ll * (mp[i] - 1) / 2;               
        for (lol j = i + 1; j < (1ll << 10); j++)
        {
            if ((i & j))
            {
                ans += mp[i] * 1ll * mp[j];
            }
        }
    }
    cout << ans;

    return 0;
}