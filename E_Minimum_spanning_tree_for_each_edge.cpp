#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol mx[300005][18];
lol blift[300005][18];
lol level[300005];
lol n, m;
map<lol, vector<pair<lol, lol>>> mp1;
void dfs(lol i, lol p, lol c, bool visit[], lol l)
{
    level[i] = l;
    blift[i][0] = p;
    visit[i] = true;
    for (lol j = 1; j < 18; j++)
    {
        if (blift[i][j - 1] != -1)
        {
            blift[i][j] = blift[blift[i][j - 1]][j - 1];
        }
        else
            break;
    }
    mx[i][0] = c;
    for (lol j = 1; j < 18; j++)
    {

        if (blift[i][j - 1] != -1)
        {
            mx[i][j] = max(mx[i][j - 1], mx[blift[i][j - 1]][j - 1]);
        }
        else
            break;
    }
    for (auto j = 0; j < mp1[i].size(); j++)
    {
        if (!visit[mp1[i][j].first])
        {
            dfs(mp1[i][j].first, i, mp1[i][j].second, visit, l + 1);
        }
    }
}
void pre()
{

    memset(blift, -1, sizeof(blift));
    memset(mx, -1, sizeof(mx));
    memset(level, -1, sizeof(level));
    bool visit[n + 1];
    for (lol i = 0; i <= n; i++)
        visit[i] = false;

    dfs(1, -1, -1, visit, 0);
}

lol solve(lol A, lol B)
{
    lol a = A;
    lol b = B;
    lol lca;
    if (a == b)
    {
        return 0;
    }
    if (level[a] < level[b])
        swap(a, b);
    while (1)
    {
        lol j;
        for (j = 17; j >= 0; j--)
        {
            if (blift[a][j] == -1)
                continue;
            else if (level[blift[a][j]] <= level[b])
            {
                continue;
            }
            else
                break;
        }
        if (j != -1)
            a = blift[a][j];
        else
            break;
    }
    if (level[a] != level[b])
        a = blift[a][0];
    if (a == b)
        lca = a;
    else
    {
        while (1)
        {
            lol j;
            for (j = 17; j >= 0; j--)
            {

                if (blift[a][j] == -1 || blift[b][j] == -1)
                    continue;
                else if (blift[a][j] == blift[b][j])
                {
                    continue;
                }
                else
                    break;
            }
            if (j < 0)
                break;
            else
            {
                a = blift[a][j];
                b = blift[b][j];
            }
        }
        lca = blift[a][0];
    }
    a = A;
    b = B;
    lol v = LONG_LONG_MIN;
    while (1)
    {
        lol j;
        for (j = 17; j >= 0; j--)
        {
            if (blift[a][j] == -1)
                continue;
            else if (level[blift[a][j]] <= level[lca])
                continue;
            else
                break;
        }
        if (j < 0)
            break;
        else
        {
            v = max(v, mx[a][j]);
            a = blift[a][j];
        }
    }
    if (level[a] != level[lca])
        v = max(v, mx[a][0]);

    while (1)
    {
        lol j;
        for (j = 17; j >= 0; j--)
        {
            if (blift[b][j] == -1)
                continue;
            else if (level[blift[b][j]] <= level[lca])
                continue;
            else
                break;
        }
        if (j < 0)
            break;
        else
        {
            v = max(v, mx[b][j]);
            b = blift[b][j];
        }
    }
    if (level[b] != level[lca])
        v = max(v, mx[b][0]);
    return v;
}
class DisjSet
{
    lol *rank, *parent, n;

public:
    DisjSet(lol n)
    {
        rank = new lol[n];
        parent = new lol[n];
        this->n = n;
        makeSet();
    }

    void makeSet()
    {
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {

        if (parent[x] != x)
        {

            parent[x] = find(parent[x]);
        }

        return parent[x];
    }

    void Union(int x, int y)
    {

        int xset = find(x);
        int yset = find(y);

        if (xset == yset)
            return;

        if (rank[xset] < rank[yset])
        {
            parent[xset] = yset;
        }
        else if (rank[xset] > rank[yset])
        {
            parent[yset] = xset;
        }

        else
        {
            parent[yset] = xset;
            rank[xset] = rank[xset] + 1;
        }
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    vector<pair<lol, vector<lol>>> edge;
    for (lol i = 0; i < m; i++)
    {
        lol a, b, c;
        cin >> a >> b >> c;

        edge.push_back({c, {a, b, i}});
    }
    sort(edge.begin(), edge.end());
    DisjSet s(n + 1);
    bool used[m];
    memset(used, false, sizeof(used));
    lol ans = 0;
    for (lol i = 0; i < edge.size(); i++)
    {
        lol p1 = s.find(edge[i].second[0]);
        lol p2 = s.find(edge[i].second[1]);
        if (p1 != p2)
        {
            used[edge[i].second[2]] = true;
            mp1[edge[i].second[0]].push_back({edge[i].second[1], edge[i].first});
            mp1[edge[i].second[1]].push_back({edge[i].second[0], edge[i].first});
            s.Union(edge[i].second[0], edge[i].second[1]);
            ans += edge[i].first;
        }
    }

    // mp1 is msp;
    pre();
    lol wow[m];
    for (lol i = 0; i < edge.size(); i++)
    {
        if (used[edge[i].second[2]])
        {
            wow[edge[i].second[2]] = ans;
        }
        else
        {
            wow[edge[i].second[2]] = ans - solve(edge[i].second[0], edge[i].second[1]) + edge[i].first;
        }
    }
    for (lol i = 0; i < m; i++)
    {
        cout << wow[i] << '\n';
    }

    return 0;
}