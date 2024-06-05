#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol ans = 0;
        map<pair<lol, lol>, map<lol, lol>> mp;
        for (lol i = 2; i < n; i++)
        {
            mp[{a[i - 2], a[i - 1]}][a[i]]++;
        }
        for (auto p : mp)
        {
            lol sum = 0;
            for (auto e : p.second)
            {
                sum += e.second;
            }
            for (auto e : p.second)
            {
                ans += (sum - e.second)*1ll*(e.second);
            }
        }
        mp.clear();
        for (lol i = 2; i < n; i++)
        {
            mp[{a[i - 2], a[i]}][a[i - 1]]++;
        }
        for (auto p : mp)
        {
            lol sum = 0;
            for (auto e : p.second)
            {
                sum += e.second;
            }
            for (auto e : p.second)
            {
                ans += (sum - e.second)*1ll*(e.second);
            }
        }
        mp.clear();
        for (lol i = 2; i < n; i++)
        {
            mp[{a[i - 1], a[i]}][a[i - 2]]++;
        }
        for (auto p : mp)
        {
            lol sum = 0;
            for (auto e : p.second)
            {
                sum += e.second;
            }
            for (auto e : p.second)
            {
                ans += (sum - e.second)*1ll*(e.second);
            }
        }
        ans /= 2ll;
        cout << ans << '\n';
    }

    return 0;
}
