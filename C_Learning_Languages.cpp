#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol par[105];
lol Rank[105];
lol find(lol a)
{
    if (par[a] == a)
    {
        return a;
    }
    return par[a] = find(par[a]);
}
void unio(lol a, lol b)
{
    a = find(a);
    b = find(b);
    if (a == b)
        return;
    if (Rank[a] <= Rank[b])
    {
        Rank[b] += Rank[a];
        par[a] = b;
    }
    else
    {
        Rank[a] += Rank[b];
        par[b] = a;
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    set<lol> a[n + 1];
    bool f = true;
    for (lol i = 1; i <= n; i++)
    {
        lol c;
        cin >> c;
        set<lol> x;
        while (c--)
        {
            f = false;
            lol v;
            cin >> v;
            a[i].insert(v);
        }
    }
    if (f)
        cout << n;
    else
    {
        lol dp[n + 1][n + 1];
        for (lol i = 1; i <= n; i++)
            for (lol j = 1; j <= n; j++)
                dp[i][j] = LONG_LONG_MAX;
        for (lol q = 1; q <= m; q++)
        {
            for (lol i = 1; i <= n; i++)
            {
                for (lol j = 1; j <= n; j++)
                {
                    if (i == j)
                        dp[i][j] = 0;
                    else
                    {
                        dp[i][j] = min(dp[i][j], 2ll - (long long)(a[i].count(q) + a[j].count(q)));
                    }
                }
            }
        }
        vector<vector<lol>> edg;
        for (lol i = 1; i <= n; i++)
        {
            for (lol j = i + 1; j <= n; j++)
            {
                edg.push_back({dp[i][j], i, j});
            }
        }
        sort(edg.begin(), edg.end());
        for (lol i = 1; i <= n; i++)
        {
            Rank[i] = 1;
            par[i] = i;
        }
        lol ans = 0;
        for (auto e : edg)
        {
            if (find(e[2]) != find(e[1]))
            {
                unio(e[1], e[2]);
                ans += e[0];
            }
        }
        cout << ans;
    }

    return 0;
}