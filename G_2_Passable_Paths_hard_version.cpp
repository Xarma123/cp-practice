#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol d[200005];
lol blift[200005][30];
map<lol, vector<lol>> mp;
void dfs(lol c, lol p, lol l)
{
    blift[c][0] = p;
    for (lol i = 1; i < 30; i++)
    {
        blift[c][i] = blift[blift[c][i - 1]][i - 1];
    }
    d[c] = l;
    for (auto e : mp[c])
        if (e != p)
            dfs(e, c, l + 1);
}
lol lca(lol a, lol b)
{
    if (d[a] < d[b])
        swap(a, b);
    lol c = d[a] - d[b];
    for (lol i = 0; i < 30; i++)
    {
        if ((c & (1ll << i)))
        {
            a = blift[a][i];
        }
    }
    for (lol i = 29; i >= 0; i--)
    {
        if (blift[a][i] != blift[b][i])
        {
            a = blift[a][i];
            b = blift[b][i];
        }
    }
    if (a != b)
        a = blift[a][0];
    return a;
}
lol dis(lol a, lol b)
{
    lol c = lca(a, b);
    return d[a] + d[b] - 2ll * d[c];
}
bool cmp(lol a, lol b)
{
    return d[a] > d[b];
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    for (lol i = 0; i < n - 1; i++)
    {
        lol a, b;
        cin >> a >> b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    dfs(1, -1, 0);
    lol q;
    cin >> q;
    while (q--)
    {
        lol k;
        cin >> k;
        lol p[k];
        for (lol i = 0; i < k; i++)
            cin >> p[i];
        sort(p, p + k, cmp);
        lol f = p[0];
        lol s = -1;
        for (lol i = 1; i < k; i++)
        {
            if (lca(f, p[i]) != p[i])
            {
                s = p[i];
                break;
            }
        }
        if (s == -1)
            cout << "YES\n";
        else
        {
            bool ans = true;
            for (lol i = 0; i < k; i++)
            {
                if (dis(s, f) != dis(s, p[i]) + dis(p[i], f))
                    ans = false;
            }
            if (ans)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    return 0;
}