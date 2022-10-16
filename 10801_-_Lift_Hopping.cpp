#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    lol k;
    while (cin >> n >> k)
    {
        lol time[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> time[i];
        }
        cin.ignore();
        vector<lol> a[n];
        for (lol i = 0; i < n; i++)
        {
            string s;
            lol floor;
            getline(cin, s);
            stringstream ss(s);
            while (ss >> floor)
                a[i].push_back(floor);
        }
        map<pair<lol, lol>, vector<pair<pair<lol, lol>, lol>>> mp;
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < a[i].size(); j++)
            {
                if (a[i][j] == 0)
                {
                    mp[{-1, -1}].push_back({{i, 0}, 0});
                    mp[{i, 0}].push_back({{-1, -1}, 0});
                }
                for (lol k = j + 1; k < a[i].size(); k++)
                {
                    pair<lol, lol> a1 = {i, a[i][j]};
                    pair<lol, lol> a2 = {i, a[i][k]};
                    lol c = abs(a1.second - a2.second) * 1ll * time[i];
                    mp[a1].push_back({a2, c});
                    mp[a2].push_back({a1, c});
                }
            }
            for (lol j = 0; j < a[i].size(); j++)
            {
                for (lol k = i + 1; k < n; k++)
                {
                    pair<lol, lol> a1 = {i, a[i][j]};
                    if (binary_search(a[k].begin(), a[k].end(), a[i][j]))
                    {
                        pair<lol, lol> a2 = {k, a[i][j]};
                        lol c = 60;
                        mp[a1].push_back({a2, c});
                        mp[a2].push_back({a1, c});
                    }
                }
            }
        }
        map<pair<lol, lol>, lol> dis;
        set<pair<lol, pair<lol, lol>>> dij;
        dij.insert({0, {-1, -1}});
        lol ans = LONG_LONG_MAX;
        while (!dij.empty())
        {
            pair<lol, pair<lol, lol>> top = (*dij.begin());
            lol a = top.first;
            pair<lol, lol> b = top.second;

            dij.erase(dij.begin());

            if (dis.count(b))
            {
                if (dis[b] < a)
                    continue;
            }
            dis[b] = a;

            if (b.second == k)
                ans = min(ans, a);
            for (auto e : mp[b])
            {
                if (dis.count(e.first))
                {
                    if (a + e.second < dis[e.first])
                    {
                        dij.insert({a + e.second, e.first});
                    }
                }
                else
                    dij.insert({a + e.second, e.first});
            }
        }
        if (ans == LONG_LONG_MAX)
            cout << "IMPOSSIBLE" << endl;
        else
            cout << ans << endl;
    }

    return 0;
}