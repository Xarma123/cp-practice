#include <bits/stdc++.h>
#define lol long long
using namespace std;
map<lol, vector<pair<lol, lol>>> mp;
pair<lol, lol> dfs(lol c, lol p)
{
    lol v = 0;
    vector<vector<lol>> q;
    for (auto e : mp[c])
    {
        if (e.first != p)
        {
            pair<lol, lol> a = dfs(e.first, c);
            v += 2ll * e.second;
            v += a.first;
            q.push_back({a.first, e.second, a.second});
        }
    }
    lol s2 = v;
    for (auto e : q)
    {
        v -= e[1] + e[0];
        v += e[2];
        s2 = min(s2, v);
        v += e[1] + e[0];
        v -= e[2];
    }
    return {v, s2};
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    for (lol i = 0; i < n - 1; i++)
    {
        lol a, b, c;
        cin >> a >> b >> c;
        mp[a].push_back({b, c});
        mp[b].push_back({a, c});
    }
    cout << dfs(1, 0).second;

    return 0;
}