#include <bits/stdc++.h>
#define lol long long
using namespace std;
// Second best mst

vector<pair<lol, lol>> g[105];
lol parent[105], sz[105];
lol find(lol a)
{
    if (parent[a] == -1)
        return a;
    return parent[a] = find(parent[a]);
}
void unio(lol a, lol b)
{
    lol ap = find(a);
    lol bp = find(b);
    if (sz[ap] <= sz[bp])
    {
        parent[ap] = bp;
        sz[bp] += sz[ap];
    }
    else
    {
        parent[bp] = ap;
        sz[ap] += sz[bp];
    }
}

lol blift[105][27];
lol mx[105][27];
lol level[105];
void dfs(lol c, lol p, lol l, lol w)
{
    blift[c][0] = p;
    level[c] = l;
    for (lol i = 1; i < 27; i++)
    {
        blift[c][i] = blift[blift[c][i - 1]][i - 1];
    }
    mx[c][0] = w;
    for (lol i = 1; i < 27; i++)
    {
        mx[c][i] = max(mx[c][i - 1], mx[blift[c][i - 1]][i - 1]);
    }
    for (auto e : g[c])
    {
        if (e.first != p)
        {
            dfs(e.first, c, l + 1, e.second);
        }
    }
}
lol val(lol a, lol b)
{
    lol A = a, B = b;
    if (level[a] < level[b])
        swap(a, b);
    lol d = level[a] - level[b];
    for (lol i = 26; i >= 0; i--)
    {
        if (((d >> i) & 1))
        {
            a = blift[a][i];
        }
    }
    for (lol i = 26; i >= 0; i--)
    {
        if (blift[a][i] != blift[b][i])
        {
            a = blift[a][i];
            b = blift[b][i];
        }
    }
    if (a != b)
    {
        a = blift[a][0];
    }
    d = level[A] - level[a];
    lol m = 0;
    for (lol i = 26; i >= 0; i--)
    {
        if (((d >> i) & 1))
        {
            m = max(m, mx[A][i]);
            A = blift[A][i];
        }
    }
    d = level[B] - level[a];

    for (lol i = 26; i >= 0; i--)
    {
        if (((d >> i) & 1))
        {
            m = max(m, mx[B][i]);
            B = blift[B][i];
        }
    }
    return m;
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
        for (lol i = 0; i < 105; i++)
        {
            g[i].clear();
        }
        memset(blift, 0, sizeof(blift));
        memset(level, 0, sizeof(level));
        memset(mx, 0, sizeof(mx));
        lol n, m;
        cin >> n >> m;
        memset(parent, -1, sizeof(parent));
        memset(sz, 1, sizeof(sz));
        vector<vector<lol>> edge;
        while (m--)
        {
            lol a, b, c;
            cin >> a >> b >> c;
            edge.push_back({c, a, b});
        }
        sort(edge.begin(), edge.end());
        vector<vector<lol>> sedge;
        lol s1 = 0;
        for (auto e : edge)
        {
            if (find(e[1]) != find(e[2]))
            {
                s1 += e[0];
                unio(e[1], e[2]);
                g[e[1]].push_back({e[2], e[0]});
                g[e[2]].push_back({e[1], e[0]});
            }
            else
            {
                sedge.push_back(e);
            }
        }
        dfs(1, 0, 1, 0);
        lol s2 = LONG_LONG_MAX;
        for (auto e : sedge)
        {
            lol c = val(e[1], e[2]);
            s2 = min(s2, s1 - c + e[0]);
        }
        cout << s1 << " " << s2 << endl;
    }

    return 0;
}