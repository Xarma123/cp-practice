#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, k, d;
    cin >> n >> k >> d;
    set<lol> p;
    for (lol i = 0; i < k; i++)
    {
        lol v;
        cin >> v;
        p.insert(v);
    }

    map<lol, vector<pair<lol, lol>>> mp;
    for (lol i = 0; i < n - 1; i++)
    {
        lol a, b;
        cin >> a >> b;
        mp[a].push_back({b, i + 1});
        mp[b].push_back({a, i + 1});
    }
    lol dis[n + 1];
    for (lol i = 1; i <= n; i++)
    {
        dis[i] = LONG_LONG_MAX;
    }
    set<lol> edg;
    queue<lol> q;
    lol baap[n + 1];
    for (auto e : p)
    {
        q.push(e);
        dis[e] = 0;
        baap[e] = 0;
    }
    cout << (long long)p.size() - 1 << '\n';
    while (!q.empty())
    {
        lol a = q.front();
        q.pop();
        if (dis[a] == d)
        {
            for (auto e : mp[a])
            {
                if (baap[a] != e.first)
                    edg.insert(e.second);
            }
            continue;
        }
        for (auto e : mp[a])
        {
            if (dis[e.first] == LONG_LONG_MAX)
            {
                dis[e.first] = dis[a] + 1;
                baap[e.first] = a;
                q.push(e.first);
            }
            else if (e.first != baap[a])
            {

                edg.insert(e.second);
            }
        }
    }
    for (auto e : edg)
        cout << e << " ";

    return 0;
}
