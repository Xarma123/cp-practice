#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol p[100005];
lol h[100005];
lol sz[100005];
//a
map<lol, vector<lol>> mp;
void dfs(lol c, lol pa)
{
    sz[c] = p[c];
    for (auto e : mp[c])
    {
        if (e != pa)
        {
            dfs(e, c);
            sz[c] += sz[e];
        }
    }
}
bool dfs2(lol c, lol pa)
{
    if ((sz[c] + h[c]) % 2 != 0)
        return false;
    lol g = (sz[c] + h[c]) / 2;
    lol b = sz[c] - g;
    if (!(g <= sz[c] && g >= 0))
        return false;
    lol b1 = 0;
    lol g1 = 0;
    for (auto e : mp[c])
    {
        if (e != pa)
        {
            if (!dfs2(e, c))
                return false;
            b1 += sz[e] - ((sz[e] + h[e]) / 2);
            g1 += ((sz[e] + h[e]) / 2);
        }
    }
    if (g1 > g)
    {
        return false;
    }
    g -= g1;
    if (b1 <= g + b && b1 >= b - p[c])
    {
        return true;
    }

    return false;
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
        for (int i = 1; i <= n; i++)
            cin >> p[i];
        for (int i = 1; i <= n; i++)
            cin >> h[i];
        for (int i = 1; i < n; i++)
        {
            lol a, b;
            cin >> a >> b;
            mp[a].push_back(b);
            mp[b].push_back(a);
        }
        dfs(1, -1);
        if (dfs2(1, -1))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}