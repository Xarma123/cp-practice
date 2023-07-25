#include <bits/stdc++.h>
using namespace std;
#define lol long long

map<lol, vector<pair<lol, lol>>> mp;
void dfs(lol c, lol g, lol ans[])
{
    ans[c] = g;
    for (auto e : mp[c])
    {
        if (ans[e.first] == LONG_LONG_MIN)
        {
            dfs(e.first, ans[c] + e.second, ans);
        }
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

        mp.clear();
        lol n, m;
        cin >> n >> m;
        vector<vector<lol>> v;
        while (m--)
        {
            lol a, b, d;
            cin >> a >> b >> d;
            v.push_back({a, b, d});
            mp[b].push_back({a, d});
            mp[a].push_back({b, -d});
        }
        lol ans[n + 1];
        for (lol i = 0; i <= n; i++)
        {
            ans[i] = LONG_LONG_MIN;
        }

        for (lol i = 0; i <= n; i++)
        {
            if (ans[i] == LONG_LONG_MIN)
            {
                dfs(i, 0, ans);
            }
        }
        bool q = true;
        for (auto e : v)
        {
            if (ans[e[0]] != LONG_LONG_MIN && ans[e[1]] != LONG_LONG_MIN)
            {
                q &= ((ans[e[1]] + e[2]) == ans[e[0]]);
            }
        }
        if (q)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}