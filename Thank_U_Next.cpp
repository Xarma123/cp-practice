#include <bits/stdc++.h>
using namespace std;
#define lol long long
map<lol, vector<pair<lol, lol>>> mp;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, m, k;
        cin >> n >> m >> k;
        mp.clear();
        pair<lol, lol> a[k];
        for (lol i = 0; i < k; i++)
        {
            cin >> a[i].second;
        }
        for (lol i = 0; i < k; i++)
        {
            cin >> a[i].first;
            a[i].first--;
        }
        sort(a, a + k);
        while (m--)
        {
            lol x, y;
            cin >> x >> y;
            mp[x].push_back({y, 1});
            mp[y].push_back({x, 1});
        }
        for (lol i = 0; i < k; i++)
        {
            mp[0].push_back({a[i].second, a[k - 1].first - a[i].first});
            mp[a[i].second].push_back({0, a[k - 1].first - a[i].first});
        }
        lol d[n + 1];
        for (lol i = 0; i <= n; i++)
        {
            d[i] = LONG_LONG_MAX;
        }

        set<pair<lol, lol>> x;
        x.insert({0, 0});
        while (!x.empty())
        {
            pair<lol, lol> top = (*x.begin());
            x.erase(x.begin());
            if (d[top.second] <= top.first)
                continue;
            d[top.second] = top.first;
            for (auto e : mp[top.second])
            {
                if (d[e.first] > top.first + e.second)
                {
                    x.insert({top.first + e.second, e.first});
                }
            }
        }
        lol i;
        for (i = 0; i <= n; i++)
        {
            if (d[i] > a[k - 1].first)
                break;
        }
        if (i <= n)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}