#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n;
    cin >> n;
    lol p[n];

    for (lol i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lol b[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    map<lol, multiset<pair<lol, lol>>> mp;
    for (lol i = 0; i < n; i++)
    {
        mp[a[i]].insert(make_pair(p[i], b[i]));
        mp[b[i]].insert(make_pair(p[i], a[i]));
    }
    lol m;
    cin >> m;
    while (m--)
    {
        lol c;
        cin >> c;
        if (mp[c].empty())
            cout << -1 << " ";
        else
        {
            cout << (*mp[c].begin()).first << " ";
            mp[(*mp[c].begin()).second].erase(mp[(*mp[c].begin()).second].find(make_pair((*mp[c].begin()).first, c)));
            mp[c].erase(mp[c].begin());
        }
    }

    return 0;
}