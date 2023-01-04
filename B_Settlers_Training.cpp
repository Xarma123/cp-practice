#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, k;
    cin >> n >> k;
    lol a[n];
    map<lol, lol> mp;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    lol ans = 0;
    while (mp[k] != n)
    {
        auto it = mp.rbegin();
        while (it != mp.rend())
        {
            pair<lol, lol> e = (*it);
            if (e.second && e.first != k)
            {
                mp[e.first]--;
                mp[e.first + 1]++;
            }
            it++;
        }
       
        ans++;
    }
    cout << ans;

    return 0;
}