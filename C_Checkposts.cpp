#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol v[100005];
map<lol, vector<lol>> mp;
lol vis[100005];
lol ans = 1;
lol p = 0;
lol d[100005];
lol l[100005];
lol t = 0;
lol mod = 1e9 + 7;
stack<lol> x;
void dfs(lol c)
{
    d[c] = ++t;
    l[c] = d[c];
    vis[c] = 1;
    x.push(c);
    for (auto e : mp[c])
    {
        if (vis[e] == 0)
        {
            dfs(e);
            l[c] = min(l[c], l[e]);
        }
        else if (vis[e] == 1)
        {
            l[c] = min(l[c], d[e]);
        }
       
    }

    if (d[c] == l[c])
    {
        lol mnp = LONG_LONG_MAX;
        lol f = 0;
        while (x.top() != c)
        {
            lol q = x.top();
            x.pop();
            if (v[q] < mnp)
            {
                mnp = v[q];
                f = 1;
            }
            else if (v[q] == mnp)
            {
                f++;
            }
            vis[q] = 2;
        }
        if (v[c] < mnp)
        {
            mnp = v[c];
            f = 1;
        }
        else if (v[c] == mnp)
        {
            f++;
        }

        vis[c] = 2;
        p += mnp;
        ans = (ans * 1ll * f) % mod;
        x.pop();
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    for (lol i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    lol m;
    cin >> m;
    while (m--)
    {
        lol a, b;
        cin >> a >> b;
        mp[a].push_back(b);
    }
    for (lol i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
            dfs(i);
    }
    cout << p << " " << ans;

    return 0;
}