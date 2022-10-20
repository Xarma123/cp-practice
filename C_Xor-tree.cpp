#include <bits/stdc++.h>
#define lol long long
using namespace std;
map<lol, vector<lol>> mp;
lol v[100005];
lol g[100005];

vector<lol> ans;
void dfs(lol c, lol p, lol d, lol qe, lol qod)
{
    if (d % 2)
    {
        if (qod)
        {
            v[c - 1] = 1 - v[c - 1];
        }
        if (v[c - 1] != g[c - 1])
        {
            qod = 1 - qod;
            v[c - 1] = 1 - v[c - 1];
            ans.push_back(c);
        }
    }
    else
    {
        if (qe)
        {
            v[c - 1] = 1 - v[c - 1];
        }
        if (v[c - 1] != g[c - 1])
        {
            qe = 1 - qe;
            v[c - 1] = 1 - v[c - 1];
            ans.push_back(c);
        }

    }
    for (auto e : mp[c])
    {
        if (e != p)
        {
            dfs(e, c, d+1,qe,qod);
        }
    }
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

    for (lol i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (lol i = 0; i < n; i++)
    {
        cin >> g[i];
    }
    dfs(1, 0, 0, 0, 0);
    cout << ans.size() << endl;
    for (auto e : ans)
        cout << e << endl;

    return 0;
}