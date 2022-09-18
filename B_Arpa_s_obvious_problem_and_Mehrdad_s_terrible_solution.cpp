#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n;
    cin >> n;
    lol x;
    cin >> x;
    lol a[n];
    map<lol, lol> mp;
    lol ans = 0;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        ans += mp[a[i]];
        mp[(a[i] ^ x)]++;
    }
    cout<<ans;

    return 0;
}