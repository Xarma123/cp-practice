#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n;
    cin >> n;
    lol a[n];
    lol b[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    map<lol, lol> mp;
    for (lol i = 0; i < n; i++)
    {
        cin >> b[i];
        mp[b[i]] = i;
    }
    lol mx = -1;
    lol ans = 0;
    for (lol i = 0; i < n; i++)
    { 
        if(mp[a[i]]<mx)
        {
            ans++;
        }
        mx=max(mx,mp[a[i]]);
    } 
    cout<<ans;

    return 0;
}