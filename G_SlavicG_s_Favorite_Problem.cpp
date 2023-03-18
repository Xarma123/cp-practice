#include <bits/stdc++.h>
#define lol long long
using namespace std;
map<lol, vector<pair<lol, lol>>> mp;
void dfs(lol c, lol p, lol till, lol dp[])
{
    dp[c] = till;
    for (auto e : mp[c])
    {
        if (e.first != p)
        {
            dfs(e.first, c, (till ^ e.second), dp);
        }
    }
}
void dfs1(lol c, lol p, lol target, bool inc, set<lol> &avoid)
{
    if (target == c)
        inc = true;
    if (inc)
        avoid.insert(c);
    for (auto e : mp[c])
    {
        if (e.first != p)
            dfs1(e.first, c, target, inc, avoid);
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, a, b;

        mp.clear();
        cin >> n >> a >> b;
        for (lol i = 0; i < n - 1; i++)
        {
            lol x, y, c;
            cin >> x >> y >> c;
            mp[x].push_back({y, c});
            mp[y].push_back({x, c});
        }
        lol dpa[n + 1];
        dfs(a, -1, 0, dpa);
        set<lol> avoid;
        dfs1(a, -1, b, false, avoid);
        lol dpb[n + 1];
        dfs(b, -1, 0, dpb);
        set<lol> x;
        for (lol i = 0; i < n; i++)
        {
            if (!avoid.count(i + 1))
                x.insert(dpa[i + 1]);
        }
        bool ans = false;
        for (lol i = 0; i < n; i++)
        {
            if (x.count(dpb[i + 1]) && i + 1 != b)
            {
                ans = true;
            }
        }

        if (ans || dpa[b] == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}