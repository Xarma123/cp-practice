#include <bits/stdc++.h>
#define lol long long
using namespace std;
map<lol, vector<lol>> mp;
vector<lol> q;
void dfs(lol c, bool vis[])
{
    vis[c] = true;
    q.push_back(c);
    for (auto e : mp[c])
    {
        if (!vis[e])
            dfs(e, vis);
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m, k;
    cin >> n >> m >> k;
    lol c[n + 1];
    bool vis[n + 1];
    for (lol i = 1; i <= n; i++)
    {
        cin >> c[i];
        vis[i] = false;
    }
    while (m--)
    {
        lol l, r;
        cin >> l >> r;
        mp[l].push_back(r);
        mp[r].push_back(l);
    }
    lol ans = 0;
    for (lol i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            q.clear();
            dfs(i, vis);
            map<lol, lol> mp;
            lol mx = 0;
            for (auto e : q)
            {
                mp[c[e]]++;
                mx = max(mx, mp[c[e]]);
            }
            ans += q.size() - mx;
        }
    }
    cout << ans;

    return 0;
}