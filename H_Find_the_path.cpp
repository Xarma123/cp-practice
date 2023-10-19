#include <bits/stdc++.h>
using namespace std;
#define lol long long
// a
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("path.in", "r", stdin);
   
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, m, u, l, k;
        cin >> n >> m >> u >> l >> k;
        map<lol, vector<pair<lol, lol>>> mp;
        vector<vector<lol>> edg;
        while (m--)
        {
            lol a, b, c;
            cin >> a >> b >> c;
            edg.push_back({a, b, c});
            mp[a].push_back({b, c});
            mp[b].push_back({a, c});
        }
        queue<lol> q;
        q.push(u);
        lol d[n + 1];
        for (lol i = 0; i <= n; i++)
        {
            d[i] = LONG_LONG_MAX;
        }
        d[u] = 0;

        while (!q.empty())
        {
            lol a = q.front();
            q.pop();
           
            for (auto e : mp[a])
            {
                if (d[e.first] == LONG_LONG_MAX)
                {
                    d[e.first] = d[a] + 1;
                    q.push(e.first);
                }
            }
        }
        lol ans = LONG_LONG_MIN;
        for (auto e : edg)
        {
            if (d[e[0]] < k || d[e[1]] < k)
            {
                ans = max(ans, e[2]);
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
