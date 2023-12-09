#include <bits/stdc++.h>
using namespace std;
#define lol long long
map<lol, vector<lol>> mp;
map<lol, lol> cmp;
lol v;
void dfs(lol c)
{
    cmp[c] = v;
    for (auto e : mp[c])
    {
        if (!mp.count(e))
            dfs(e);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    mp.clear();
    cmp.clear();
    v = 0;
    while (m--)
    {
        lol a, b;
        cin >> a >> b;
        mp[a].push_back(b);
    }
    for (lol i = 1; i <= n; i++)
    {
        if (!mp.count(i))
        {
            dfs(i);
            v++;
        }
    }
    map<lol, lol> sz;
    for (lol i = 1; i <= n; i++)
    {
        sz[cmp[i]]++;
    }
    lol q;
    cin >> q;
    vector<lol> ans;
    while (q--)
    {
        lol a;
        cin >> a;
        ans.push_back(sz[cmp[a]]);
    }

    return 0;
}
