#include <bits/stdc++.h>
using namespace std;
#define lol long long
pair<vector<lol>,vector<lol>> solve(lol a[], lol b[], lol n, lol m, lol k)
{
    unordered_map<lol, vector<lol>> mp;
    vector<lol> p(),dis[n+1]
    for (lol i = 0; i < m; i++)
    {
        if (i == k)
            continue;
        mp[a[i]].push_back(b[i]);
        mp[b[i]].push_back(a[i]);
    }
    bool vis[n + 1];
    memset(vis, false, sizeof(vis));
    queue<lol> q;
    q.push(1);
    vis[1] = true;
    lol d = 0;
    while (!q.empty())
    {
        lol c = q.size();
        while (c--)
        {
            lol v = q.front();
            if (v == n)
                return d;
            q.pop();
            for (auto e : mp[v])
            {
                if (!vis[e])
                {
                    vis[e] = true;
                    q.push(e);
                }
            }
        }
        d++;
    }
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    lol a[m];
    for (lol i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    cin >> m;
    lol b[m];
    for (lol i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    map<pair<lol, lol>, lol> mp;
    for (lol i = 0; i < m; i++)
    {
        mp[{a[i], b[i]}] = i;
        mp[{b[i], a[i]}] = i;
    }

    lol d[n + 1];
    lol p[n + 1];
    for (lol i = 0; i <= n; i++)
    {
        d[i] = INT_MAX;
        p[i] = -1;
    }
    d[1] = 0;
    p[1] = 1;
    for (lol i = 0; i < n; i++)
    {
        for (lol j = 0; j < m; j++)
        {
            if (d[b[j]] > d[a[j]] + 1)
            {
                p[b[j]] = a[j];
            }
            if (d[a[j]] > d[b[j]] + 1)
            {
                p[a[j]] = b[j];
            }
            d[b[j]] = min(d[b[j]], d[a[j]] + 1);
            d[a[j]] = min(d[a[j]], d[b[j]] + 1);
        }
    }
    vector<lol> ans;
    if (d[n] == INT_MAX)
    {
        for (lol i = 0; i < m; i++)
        {
            ans.push_back(-1);
        }
    }
    else
    {
        lol st = n;
        set<lol> av;
        while (st != 1)
        {
            av.insert(mp[{p[st], st}]);
            st = p[st];
        }

        for (lol i = 0; i < m; i++)
        {
            if (av.count(i))
            {
                ans.push_back(solve(a, b, n, m, i));
            }
            else
            {
                ans.push_back(d[n]);
            }
        }
    }
    for (auto e : ans)
        cout << e << endl;

    return 0;
}
