#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    lol d[2 * n + 1];
    for (int i = 0; i < 2 * n + 1; i++)
        d[i] = LONG_LONG_MAX;
    map<pair<lol, lol>, vector<pair<pair<lol, lol>, lol>>> mp;
    while (m--)
    {
        lol a, b, c;
        cin >> a >> b >> c;
        mp[{a, 0}].push_back({{b, 0}, c});
        mp[{b, 1}].push_back({{a, 1}, c});
    }
    for (lol i = 1; i <= n; i++)
    {
        mp[{i, 0}].push_back({{i, 1}, 0});
    }
    set<pair<lol, pair<lol, lol>>> x;
    x.insert({0, {1, 0}});
    while (!x.empty())
    {
        pair<lol, pair<lol, lol>> q = (*x.begin());
        x.erase(x.begin());
        lol a1 = q.second.first;
        lol a2 = q.second.second;
        a1 = a1 + n * a2;
        lol c = q.first;
        if (d[a1] <= c)
            continue;
        d[a1] = c;
        for (auto e : mp[q.second])
        {
            if (e.second + c < d[e.first.first + e.first.second * 1ll * n])
            {
                x.insert({e.second + c, {e.first.first, e.first.second}});
            }
        }
    }
    for (lol i =  2; i <= n; i++)
    {
        lol v = min(d[i], d[i + n]);
        if (v == LONG_LONG_MAX)
            v = -1;
        cout << v << " ";
    }

    return 0;
}