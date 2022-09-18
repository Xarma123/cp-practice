#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[n];
        map<lol, lol> mp;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            mp[a[i]]++;
        }
        lol mx = 0;
        for (auto i = mp.begin(); i != mp.end(); i++)
        {
            mx = max(mx, (*i).second);
        }
        lol i;
        lol ans = LONG_LONG_MIN;
        lol f = mp.size();
        for (i = 0; i <= mx; i++)
        {
            if (mx - i >= 1)
            {
                ans = max(ans, min(i, f));
            }
            else
            {
                ans = max(ans, min(i, (f - 1)));
            }
        } 
        cout<<ans<<endl;
    }

    return 0;
}