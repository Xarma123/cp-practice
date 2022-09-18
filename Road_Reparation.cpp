#include <bits/stdc++.h>
#define lol long long
using namespace std;
class DisjSet
{
    lol *rank, *parent, n;

public:
    DisjSet(int n)
    {
        rank = new lol[n];
        parent = new lol[n];
        this->n = n;
        makeSet();
    }
    void makeSet()
    {
        for (lol i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    lol find(lol x)
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
    lol n, m;
    cin >> n >> m;
    DisjSet s(n + 1);
    multiset<pair<lol, pair<lol, lol>>> e;
    while (m--)
    {
        lol a, b, c;
        cin >> a >> b >> c;
        e.insert({c, {a, b}});
    }
    lol ans = 0;
    while (e.size() > 0)
    {

        pair<lol, pair<lol, lol>> x = (*e.begin());
        if (s.find(x.second.first) != s.find(x.second.second))
        {
            ans += x.first;
            s.Union(x.second.first, x.second.second);
        }
        e.erase(x);
    }
    set<lol> p;
    for (lol i = 1; i <= n; i++)
    {
        p.insert(s.find(i));
    }
    if (p.size() == 1)
        cout << ans;
    else
        cout << "IMPOSSIBLE";
    return 0;
}