#include <bits/stdc++.h>
#define lol long long
using namespace std;
map<lol, vector<lol>> mp;
map<lol, set<pair<lol, lol>>> w;
lol sz[100005];
lol par[100005];
lol imp[100005];
lol a[100005];
void dfs(lol c, lol p)
{
    par[c] = p;
    sz[c] = 1;
    imp[c] = a[c];
    for (auto e : mp[c])
    {
        if (e != p)
        {
            dfs(e, c);
            sz[c] += sz[e];
            imp[c] += imp[e];
            w[c].insert({-sz[e], e});
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i + 1];
    }
    for (lol i = 0; i < n - 1; i++)
    {
        lol x, y;
        cin >> x >> y;
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    dfs(1, -1);
    while (m--)
    {
        lol t, x;
        cin >> t >> x;
        if (t == 1)
        {
            cout << imp[x] << '\n';
        }
        else if (w[x].size() > 0)
        {
            pair<lol, lol> pa = (*w[x].begin());
            imp[x] -= imp[pa.second];
            lol baap = par[x];
            w[baap].erase({-sz[x], x});
            par[x] = pa.second;
            w[x].erase(pa);
            sz[x] -= sz[pa.second];
            par[pa.second] = baap;
            sz[pa.second] += sz[x];
            imp[pa.second] += imp[x];
            w[pa.second].insert({-sz[x], x});
            w[baap].insert({-sz[pa.second], pa.second});
        }
    }

    return 0;
}