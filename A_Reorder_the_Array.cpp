#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n;
    cin >> n;
    lol a[n];
    map<lol, lol> mp;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    lol ans = 0;
    mp[a[0]]++;
    for (lol i = 1; i < n; i++)
    {
        auto it = mp.rbegin();
        if ((*it).first < a[i])
        {
            (*it).second--;
            ans++;
            if ((*it).second == 0)
                mp.erase(((*it).first));
        }
        else
        {
            it++;
            if (it != mp.rend())
            {
                if ((*it).first < a[i])
                {
                    (*it).second--;
                    ans++;
                    if ((*it).second == 0)
                        mp.erase(((*it).first));
                }
            }
        }
        mp[a[i]]++;
    }
    cout << ans;

    return 0;
}