#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    lol x, y, hx, hy;
    cin >> x >> y >> hx >> hy;
    vector<pair<lol, lol>> xy;
    vector<pair<lol, pair<lol, lol>>> yx;
    for (lol i = 0; i < m; i++)
    {
        lol a, b;
        cin >> a >> b;
        xy.push_back({a, b});
    }
    sort(xy.begin(), xy.end());
    for (lol i = 0; i < m; i++)
    {
        yx.push_back({xy[i].second, {xy[i].first, i}});
    }
    sort(yx.begin(), yx.end());
    map<lol, vector<pair<lol, lol>>> mp;
    mp[-1].push_back({m, ((long long)abs(x - hx) + (long long)abs(y - hy))});
    mp[m].push_back({-1, ((long long)abs(x - hx) + (long long)abs(y - hy))});
    for (lol i = 0; i < m; i++)
    {
        lol a = xy[i].first;
        lol b = xy[i].second;
        mp[-1].push_back({i, min((long long)abs(x - a), (long long)abs(y - b))});
        mp[i].push_back({-1, min((long long)abs(x - a), (long long)abs(y - b))});
        mp[m].push_back({i, min((long long)abs(hx - a), (long long)abs(hy - b))});
        mp[i].push_back({m, ((long long)abs(hx - a)+ (long long)abs(hy - b))});
    }
    for (lol i = 1; i < m; i++)
    {
        lol a = xy[i].first;
        lol b = xy[i].second;
        lol pa = xy[i - 1].first;
        lol pb = xy[i - 1].second;
        mp[i - 1].push_back({i, min((long long)abs(pa - a), (long long)abs(pb - b))});
        mp[i].push_back({i - 1, min((long long)abs(pa - a), (long long)abs(pb - b))});
        a = yx[i].second.first;
        b = yx[i].first;
        pa = yx[i - 1].second.first;
        pb = yx[i - 1].first;
        lol _i = yx[i].second.second;
        lol __i = yx[i - 1].second.second;
        mp[_i].push_back({__i, min((long long)abs(pa - a), (long long)abs(pb - b))});
        mp[__i].push_back({_i, min((long long)abs(pa - a), (long long)abs(pb - b))});
    }

    lol d[m + 2];
    for (lol i = 0; i < m + 2; i++)
    {
        d[i] = LONG_LONG_MAX;
    }

    set<pair<lol, lol>> pq;
    pq.insert({0, -1});
    while (!pq.empty())
    {
        pair<lol, lol> a = (*pq.begin());
        pq.erase(pq.begin());
        if (d[a.second + 1] <= a.first)
            continue;
        d[a.second + 1] = a.first;
        for (auto e : mp[a.second])
        {
            if (e.second + a.first < d[e.first + 1])
            {
                pq.insert({e.second + a.first, e.first});
            }
        }
    }
    cout << d[m + 1];
}