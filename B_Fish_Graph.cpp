#include <bits/stdc++.h>
#define lol long long
using namespace std;
map<lol, vector<lol>> mp;
vector<lol> dfs(lol c, lol p, lol w, bool vis[])
{
    vector<lol> ans;
    vis[c] = true;
    for (auto e : mp[c])
    {
        if (!vis[e])
        {
            ans = dfs(e, c, w, vis);
            if (ans.size())
            {
                ans.push_back(c);
                return ans;
            }
        }
        else if (e != p && e == w)
        {
            ans.push_back(c);
            return ans;
        }
    }
    return ans;
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
        lol n, m;
        cin >> n >> m;
        mp.clear();

        for (lol i = 0; i < m; i++)
        {
            lol a, b;
            cin >> a >> b;
            mp[a].push_back(b);
            mp[b].push_back(a);
        }
        vector<lol> v;
        for (lol i = 1; i <= n; i++)
        {
            if (mp[i].size() >= 4)
            {
                bool vis[n + 1];
                memset(vis, false, sizeof(vis));
                v = dfs(i, -1, i, vis);
                if (v.size())
                    break;
            }
        }
        if (v.size())
        {
            cout << "YES\n";
            set<lol> x;
            for (lol i = 0; i < v.size(); i++)
            {
                x.insert(v[i]);
            }
            lol c = 2;
            vector<lol> q;
            for (auto e : mp[v.back()])
            {
                if (e != v[0] && e != v[(long long)v.size() - 2])
                {
                    q.push_back(e);
                    c--;
                }
                if (c == 0)
                    break;
            }
            lol st = 0;
            for (lol i = 0; i < v.size(); i++)
            {
                if (v[i] == q[0] || v[i] == q[1])
                    st = i;
            }
            cout << v.size() - st + 2 << '\n';
            for (lol i = st; i < v.size() - 1; i++)
            {
                cout << v[i] << " " << v[i + 1] << '\n';
            }
            cout << v[0] << " " << v.back() << '\n';
            cout << v.back() << " " << q[0] << '\n';
            cout << v.back() << " " << q[1] << '\n';
        }
        else
            cout << "NO\n";
    }

    return 0;
}