#include <bits/stdc++.h>
#define lol long long
using namespace std;
long double cal(vector<long double> a, vector<long double> b)
{
    return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
}
lol dfs(lol c, bool vis[], map<lol, vector<lol>> &mp)
{
    lol v = 1;
    vis[c] = true;
    for (auto e : mp[c])
    {
        if (!vis[e])
        {
            v += dfs(e, vis, mp);
        }
    }
    return v;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while (1)
    {
        lol n;
        cin >> n;
        if (n == -1)
            break;
        vector<vector<long double>> c;
        for (lol i = 0; i < n; i++)
        {
            long double x, y, r;
            cin >> x >> y >> r;
            c.push_back({x, y, r});
        }
        map<lol, vector<lol>> mp;
        for (lol i = 0; i < n; i++)
        {
            for (lol j = i + 1; j < n; j++)
            {
                long double d = cal(c[i], c[j]);

                if ((d <= powl(c[i][2] + c[j][2], 2)) &&
                    (d >= powl(c[j][2] - c[i][2], 2)))
                {
                    mp[i].push_back(j);
                    mp[j].push_back(i);
                }
            }
        }
        bool vis[n];
        lol ans = 0;
        memset(vis, false, sizeof(vis));
        for (lol i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                ans = max(ans, dfs(i, vis, mp));
            }
        }
        if (ans == 1)
            cout << "The largest component contains " << ans << " ring.\n";
        else
            cout << "The largest component contains " << ans << " rings." << endl;
    }

    return 0;
}