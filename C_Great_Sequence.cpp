#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, x;
        cin >> n >> x;
        lol a[n];
        bool paired[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            paired[i] = false;
        }
        sort(a, a + n);
        map<lol, vector<lol>> mp;

        for (lol i = 0; i < n; i++)
        {
            if (mp.count(a[i]))
            {
                lol j = mp[a[i]].back();
                paired[j] = true;
                paired[i] = true;
                mp[a[i]].pop_back();
                if(mp[a[i]].size()==0)
                mp.erase(a[i]);
            }
            else
            {
                mp[(a[i] * 1ll * x)].push_back(i);
            }
        } 
        lol ans=0;
        for (lol i = 0; i < n; i++)
        {
           if(!paired[i])
           ans++;

        }
        cout<<ans<<endl;
        
    }

    return 0;
}