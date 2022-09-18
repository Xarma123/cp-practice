#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n;
    cin >> n;
    map<char, lol> mp;
    for (lol i = 0; i < n; i++)
    {
        string a;
        cin >> a;
        mp[a[0]]++;
    }
    lol ans = 0;
    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        lol x = (*i).second;
        lol y = x - x / 2;
        x = x / 2; 
        ans+=x*(x-1)/2+y*(y-1)/2;
    }
    cout<<ans;

    return 0;
}