#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n;
    cin >> n;
    lol a[n];
    lol b[n];
    lol extra=0;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    map<long double, lol> mp;
    for (lol i = 0; i < n; i++)
    {
        cin >> b[i];
        if(a[i]!=0)
        mp[((-b[i]) / (long double)a[i])]++;
        else
        {
            if(b[i]==0)
            extra++;
        }
    }
    lol ans = 0;
    for (auto i = mp.begin(); i != mp.end(); i++)
    {
        ans = max(ans, (*i).second);
    }
    cout << ans+extra;

    return 0;
}