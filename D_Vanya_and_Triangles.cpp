#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    pair<lol, lol> a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    lol ans = 0;
    for (lol i = 0; i < n; i++)
    {
        map<long double, lol> mp;
        mp.clear();
        for (lol j = i + 1; j < n; j++)
        {
            long double m;
            if (a[j].first != a[i].first)
                m = (a[j].second - a[i].second) / (long double)(a[j].first - a[i].first);
            else
                m = DBL_MAX;
            mp[m]++;
        }

        for (auto e : mp)
        {
            ans += e.second * 1ll * (n - (i + 1 + e.second));
        }
    }
    cout << ans / 2;

    return 0;
}