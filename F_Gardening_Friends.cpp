#include <bits/stdc++.h>
#define lol long long
using namespace std;
map<lol, vector<lol>> mp;
lol d[200005];
lol h[200005];
lol n, k, co;
void dfs(lol c, lol p, lol l)
{
    d[c] = l;
    h[c] = 0;
    for (auto e : mp[c])
    {
        if (e != p)
        {
            dfs(e, c, l + 1);
            h[c] = max(h[c], h[e] + 1);
        }
    }
}
lol ans;
void dfs2(lol c, lol p, lol u)
{
    ans = max(ans, max(h[c], u) * 1ll * k - d[c] * 1ll * co);
    lol f = -2, s = -2;
    for (auto e : mp[c])
    {
        if (e != p)
        {
            if (h[e] >= f)
            {
                s = f;
                f = h[e];
            }
            else if (h[e] >= s)
            {
                s = h[e];
            }
        }
    }
    for (auto e : mp[c])
    {
        if (e != p)
        {
            lol w = f;
            if (h[e] == f)
            {
                w = s;
            }
            w = max(u + 1, w + 2);
            dfs2(e, c, w);
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
        ans = LONG_LONG_MIN;
        cin >> n >> k >> co;
        for (lol i = 0; i < n - 1; i++)
        {
            lol a, b;
            cin >> a >> b;
            mp[a].push_back(b);
            mp[b].push_back(a);
        }
        dfs(1, -1, 0);
        dfs2(1, -1, 0);
        cout << ans << '\n';
    }

    return 0;
}