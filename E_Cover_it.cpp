#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, m;
        cin >> n >> m;
        map<lol, vector<lol>> mp;
        while (m--)
        {
            lol x, y;
            cin >> x >> y;
            mp[x].push_back(y);
            mp[y].push_back(x);
        }
        queue<lol> q;
        q.push(1);
        bool vis[n + 1];
        memset(vis, false, sizeof(vis));
        vis[1] = true;
        vector<vector<lol>> all;
        while (!q.empty())
        {
            lol c = q.size();
            vector<lol> a;
            while (c--)
            {
                lol v = q.front();
                a.push_back(v);
                q.pop();
                for (auto e : mp[v])
                {
                    if (!vis[e])
                    {
                        q.push(e);
                        vis[e] = true;
                    }
                }
            }
            all.push_back(a);
        }
        lol v = 0;
        for (lol i = 0; i < all.size(); i += 2)
        {
            v += all[i].size();
        }
        if (v <= n / 2ll)
        {
            cout << v << '\n';
            for (lol i = 0; i < all.size(); i += 2)
            {
                for (auto e : all[i])
                    cout << e << ' ';
            }
            cout << '\n';
        }
        else
        {
            cout << n - v << '\n';
            for (lol i = 1; i < all.size(); i += 2)
            {
                for (auto e : all[i])
                    cout << e << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}
