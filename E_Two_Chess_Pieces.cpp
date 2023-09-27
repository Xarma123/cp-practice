#include <bits/stdc++.h>
#define lol long long
using namespace std;
map<lol, vector<lol>> mp;
lol n, d;
lol blift[200005][31];
void dfs(lol c, lol p)
{
    blift[c][0] = p;
    for (lol i = 1; i < 31; i++)
    {
        blift[c][i] = blift[blift[c][i - 1]][i - 1];
    }
    for (auto e : mp[c])
    {
        if (e != p)
            dfs(e, c);
    }
}
lol anc(lol c, lol d)
{
    for (lol i = 30; i >= 0; i--)
    {
        if ((d & (1ll << i)))
        {
            c = blift[c][i];
        }
    }
    return c;
}
lol dfs2(lol c, lol p, set<lol> &x)
{
    lol q = 0;
    for (auto e : mp[c])
    {
        if (e != p)
        {
            q += dfs2(e, c, x);
        }
    }
    if (q || x.count(c))
        q++;
    return q;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> d;
    for (lol i = 0; i < n - 1; i++)
    {
        lol a, b;
        cin >> a >> b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
  

    dfs(1, 0);
    lol m1;
    cin >> m1;
    vector<lol> b(m1);
    for (lol i = 0; i < m1; i++)
    {
        cin >> b[i];
    }
    lol m2;
    cin >> m2;
    vector<lol> c(m2);
    for (lol i = 0; i < m2; i++)
    {
        cin >> c[i];
    }
    for (lol i = 0; i < m1; i++)
    {
        lol v = anc(b[i], d);
        if (v != 0)
            c.push_back(v);
    }
    for (lol i = 0; i < m2; i++)
    {
        lol v = anc(c[i], d);
        if (v != 0)
            b.push_back(v);
    }
    set<lol> x;
    for (auto e : b)
        x.insert(e);
    lol ans = 2ll * (dfs2(1, -1, x) - 1);
    x.clear();
    for (auto e : c)
        x.insert(e);
    ans += 2ll * (dfs2(1, -1, x) - 1);
    cout << ans << endl;

    return 0;
}