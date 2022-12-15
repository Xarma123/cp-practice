#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, k;
        cin >> n >> k;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol b[n];
        map<lol, lol> mp;
        for (lol i = 0; i < n; i++)
        {
            cin >> b[i];
            if (mp.count(a[i]))
                mp[a[i]] = min(mp[a[i]], b[i]);
            else
                mp[a[i]] = b[i];
        }
        vector<lol> v;
        for (auto e : mp)
            v.push_back(e.second);
        sort(v.begin(), v.end());
        if (v.size() < k)
            cout << -1 << endl;
        else
        {
            lol ans = 0;
            for (lol i = 0; i < k; i++)
            {
                ans += v[i];
            }
            cout << ans << endl;
        }
    }

    return 0;
}