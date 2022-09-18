#include <bits/stdc++.h>
#define lol long long
using namespace std;
map<lol, vector<lol>> mp;
map<lol, lol> f;
lol dfs(lol n, lol p)
{
    lol c = 1;
    for (auto e : mp[n])
    {
        if (e != p)
            c += dfs(e, n);
    }
    f[n] = c;
    return c;
}
lol ans;
lol dfs1(lol n, lol p)
{
    lol c = 0;
    if (mp[n].size() == 0)
        return 0;
    if (mp[n].size() == 1)
        return 0;
    if (mp[n].size() == 2)
    {
        for (auto e : mp[n])
        {
            if (e != p)
                c = max(c, f[e] - 1);
        }
        return c;
    }
    for (auto e : mp[n])
    {
        if (e != p)
        {
            lol v = dfs1(e, n);
            for (auto j : mp[n])
            {
                if (j != p && j != e)
                    c = max(v + f[j] - 1, c);
            }
        }
    }
    return c;
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
        lol n;
        cin >> n;
        mp.clear();
        f.clear();
        ans = 0;
        for (lol i = 0; i < n - 1; i++)
        {
            lol a, b;
            cin >> a >> b;
            mp[a].push_back(b);
            mp[b].push_back(a);
        }

        dfs(1, 0);
        mp[0].push_back(1);
        mp[1].push_back(0);
        cout << dfs1(1, 0) << endl;
    }

    return 0;
}