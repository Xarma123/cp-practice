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
        lol n, m;
        cin >> n >> m;
        lol a[n];
        map<lol, lol> mp;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            mp[a[i]]++;
        }
        multiset<lol> v;
        for (auto e : mp)
            v.insert(-e.second);
        lol ans = 0;
        multiset<lol> x;
        for (lol i = 0; i < m; i++)
        {
            lol q;
            cin >> q;
            x.insert(q);
        }
        while (!x.empty() && !v.empty())
        {
            auto it = x.lower_bound(-(*v.begin()));
            if (it != x.end())
            {
                ans += -(*v.begin());
                x.erase(it);
                v.erase(v.begin());
            }
            else
            {
                it--;
                lol q = -(*v.begin());
                ans += (*it);
                v.erase(v.begin());
                v.insert((*it) - q);
                x.erase(it);
            }
        }
        cout << ans << '\n';
    }

    return 0;
}