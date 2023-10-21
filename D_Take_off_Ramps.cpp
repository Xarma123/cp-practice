#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, l;
    cin >> n >> l;
    map<lol, vector<pair<lol, pair<lol, lol>>>> mp;
    vector<lol> v;
    for (lol i = 1; i <= n; i++)
    {
        lol x, d, t, p;
        cin >> x >> d >> t >> p;
        
        if (x - p < 0)
            continue;
        mp[x - p].push_back({x + d, {t + p, i}});
        v.push_back(x - p);
        v.push_back(x + d);
    }
    v.push_back(0);
    v.push_back(l);
    sort(v.begin(), v.end());
    for (lol i = 1; i < v.size(); i++)
    {
        if (v[i] == v[i - 1])
            continue;
        mp[v[i]].push_back({v[i - 1], {v[i] - v[i - 1], -1}});
        mp[v[i - 1]].push_back({v[i], {v[i] - v[i - 1], -1}});
    }
    set<pair<lol, lol>> x;
    x.insert({0, 0});
    map<lol, lol> d;
    map<lol, pair<lol, lol>> par;
    d[0] = 0;
    while (!x.empty())
    {
        pair<lol, lol> a = (*x.begin());
        x.erase(a);

        if (d.count(a.second) && d[a.second] < a.first)
            continue;
        for (auto e : mp[a.second])
        {
            if (d.count(e.first) && d[e.first] < e.second.first + a.first)
                continue;
            d[e.first] = e.second.first + a.first;
            par[e.first] = {a.second, e.second.second};
            x.insert({d[e.first], e.first});
        }
    }
    cout << d[l] << '\n';
    lol u = l;
    stack<lol> r;
    while (u != 0)
    {
        if (par[u].second != -1)
            r.push(par[u].second);
        u = par[u].first;
    }
    cout << r.size() << '\n';
    while (!r.empty())
    {
        cout << r.top() << " ";
        r.pop();
    }

    return 0;
}
