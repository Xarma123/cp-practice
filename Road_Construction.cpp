#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol f[200005];
lol ans2 = 1;
class DisjSet
{
    int *rank, *parent, n;

public:
    DisjSet(int n)
    {
        rank = new int[n];
        parent = new int[n];
        this->n = n;
        makeSet();
    }

    void makeSet()
    {
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            f[i] = 1;
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
            f[yset] += f[xset];
            f[xset] = 0;
        }
        else if (rank[xset] > rank[yset])
        {
            parent[yset] = xset;
            parent[yset] = xset;
            f[xset] += f[yset];
            f[yset] = 0;
        }

        else
        {
            parent[yset] = xset;
            rank[xset] = rank[xset] + 1;
            parent[yset] = xset;
            parent[yset] = xset;
            f[xset] += f[yset];
            f[yset] = 0;
        }
        ans2 = max(ans2, f[xset]);
        ans2 = max(ans2, f[yset]);
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
    lol ans = n;

    while (m--)
    {

        lol a, b;
        cin >> a >> b;
        if (s.find(a) != s.find(b))
            ans--;

        s.Union(a, b);

        cout << ans << " " << ans2 << endl;
    }

    return 0;
}