#include <bits/stdc++.h>
#define lol long long
using namespace std;
map<lol, vector<pair<lol, lol>>> mp;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    while (m--)
    {
        lol a, b, c;
        cin >> a >> b >> c;
        mp[a].push_back({b, c});
        mp[b].push_back({a, c});
    }
    lol d[n + 1];
    lol par[n + 1];
    for (lol i = 0; i <= n; i++)
    {
        d[i] = 1e18;
        par[i] = -1;
    }

    set<pair<lol, pair<lol, lol>>> x;
    x.insert({0, {1, -1}});

    while (!x.empty())
    {
        pair<lol, pair<lol, lol>> a = (*x.begin());
        x.erase(x.begin());
        if (d[a.second.first] <= a.first)
            continue;
        d[a.second.first] = a.first;
        par[a.second.first] = a.second.second;
        for (auto e : mp[a.second.first])
        {
            if (e.second + d[a.second.first] < d[e.first])
            {
                x.insert({e.second + d[a.second.first], {e.first, a.second.first}});
            }
        }
    }
    if (d[n] == (long long)1e18)
        cout << -1;
    else
    {
        lol s = n;
        stack<lol> y;
        y.push(s);
        while (par[s] != -1)
        {
            s = par[s];
            y.push(s);
        }
        while (!y.empty())
        {
            cout << y.top() << " ";
            y.pop();
        }
    }

    return 0;
}