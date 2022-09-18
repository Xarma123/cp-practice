#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    map<lol, lol> mp;
    for (lol i = 1; i <= m; i++)
    {
        mp[i % 5]++;
    }
    lol ans = 0;
    for (lol i = 1; i <= n; i++)
    {
        if (i % 5 == 0)
            ans += mp[0];
        else
            ans += mp[5 - (i % 5)];
    }
    cout << ans;

    return 0;
}