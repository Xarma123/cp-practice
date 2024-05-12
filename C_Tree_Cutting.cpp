#include <bits/stdc++.h>
using namespace std;
#define lol long long
map<lol, vector<lol>> mp;
lol ans;
lol mx;
lol dfs(lol c, lol p, bool vis[])
{
    vis[c] = true;
    lol sz = 1;
    for (auto i : mp[c])
    {
        if (!vis[i])
        {
            sz += dfs(i, c, vis);
        }
    }
    if (p == -1)
    {
        if (sz < mx)
            ans--;
    }
    else
    {
        if (sz >= mx)
        {
            sz = 0;
            ans++;
        }
    }

    return sz;
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
        lol n, k;
        cin >> n >> k;
        mp.clear();
        for (lol i = 0; i < n - 1; i++)
        {
            lol a, b;
            cin >> a >> b;
            mp[a].push_back(b);
            mp[b].push_back(a);
        }
        lol s = 0, e = n + 1;
        while (s != e - 1)
        {
            lol m = (s + e) / 2ll;
            if (m == 0 || m == 1)
            {
                s = m;
            }
            else if (m == n + 1)
            {
                e = m;
            }
            else
            {
                bool vis[n + 1];
                memset(vis, false, sizeof(vis));
                ans = 0;
                mx = m;
                dfs(1, -1, vis);
               
                if (ans >= k)
                    s = m;
                else
                    e = m;
            }
        }
        cout << s << '\n';
    }

    return 0;
}
