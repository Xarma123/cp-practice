#include <bits/stdc++.h>
using namespace std;
#define lol long long
map<lol, vector<pair<lol, lol>>> mp;
lol low[200005];
lol dis[200005];
lol e;
vector<pair<lol, pair<lol, lol>>> v;
void dfs(lol c, lol p)
{
    low[c] = dis[c] = (e++);
    for (auto e : mp[c])
    {
        if (dis[e.first] == -1)
        {
            dfs(e.first, c);
            low[c] = min(low[c], low[e.first]);
        }
        else if (e.first != p)
        {
            low[c] = min(low[c], dis[e.first]);
        }
        if (low[e.first] <= dis[c] && e.first != p)
        {
            v.push_back({e.second, {c, e.first}});
        }
    }
}
vector<lol> x;
bool q;
void dfs1(lol c, lol p)
{
    dis[c] = 1;
    x.push_back(c);
    if (c == v[0].second.second)
    {
        q = true;
        return;
    }

    for (auto e : mp[c])
    {
        if (dis[e.first] == -1 && e.first != p)
        {
            dfs1(e.first, c);
            if (q)
                return;
        }
    }
    if (q)
        return;

    x.pop_back();
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        mp.clear();
        v.clear();
        lol n, m;
        cin >> n >> m;
        for (lol i = 0; i <= n; i++)
        {
            dis[i] = -1;
        }
        e = 0;
        while (m--)
        {
            lol a, b, c;
            cin >> a >> b >> c;
            mp[a].push_back({b, c});
            mp[b].push_back({a, c});
        }
        for (lol i = 1; i <= n; i++)
        {
            if (dis[i] == -1)
                dfs(i, 0);
        }
        sort(v.begin(), v.end());
        cout << v[0].first << " ";
        for (lol i = 0; i <= n; i++)
        {
            dis[i] = -1;
        }
        x.clear();
        q = false;
        dfs1(v[0].second.first, v[0].second.second);

        cout << x.size() << '\n';
        for (auto e : x)
            cout << e << " ";
        cout << '\n';
    }

    return 0;
}
