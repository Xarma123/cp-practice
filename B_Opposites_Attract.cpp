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
    lol a[n];
    map<lol, lol> mp;
    lol ans = 0;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];

        ans += mp[-a[i]];

        mp[a[i]]++;
    }
    cout << ans;

    return 0;
}