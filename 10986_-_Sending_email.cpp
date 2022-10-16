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
    lol cae = 1;
    while (t--)
    {
        lol n, m, s, d;
        cin >> n >> m >> s >> d;
        lol dis[n];
        for (lol i = 0; i < n; i++)
        {
            dis[i] = LONG_LONG_MAX;
        }

        map<lol, vector<pair<lol, lol>>> mp;
        while (m--)
        {
            lol a, b, c;
            cin >> a >> b >> c;
            mp[a].push_back({b, c});
            mp[b].push_back({a, c});
        }
        set<pair<lol, lol>> dij;
        dij.insert({0, s});
        while (!dij.empty())
        {
            pair<lol, lol> top = (*dij.begin());
            lol a = top.first;
            lol b = top.second;
            dij.erase(dij.begin());
            if (dis[b] < a)
            {
                continue;
            }
            dis[b] = a;
            for (auto e : mp[b])
            {
                if (a + e.second < dis[e.first])
                {
                    dij.insert({a + e.second, e.first});
                }
            }
        }

        if (dis[d] != LONG_LONG_MAX)
            cout << "Case #" << cae << ": " << dis[d] << endl;
        else
            cout << "Case #" << cae << ": unreachable" << endl;
        cae++;
    }

    return 0;
}