#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, k, d;
        cin >> n >> k >> d;
        lol a[n];
        map<lol, lol> mp;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            if (i < d)
                mp[a[i]]++;
        }
        lol ans = mp.size();
        lol s = 0;
        lol e = d;
        while (e < n)
        {
            mp[a[s]]--;
            if (mp[a[s]] == 0)
                mp.erase(a[s]);
            mp[a[e]]++;
            s++;
            e++;
            ans = min(ans, (long long)mp.size());
        } 
        cout<<ans<<endl;
    }

    return 0;
}