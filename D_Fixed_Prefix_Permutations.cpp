#include <bits/stdc++.h>
#define lol long long
using namespace std;
map<pair<pair<lol, lol>, pair<lol,lol>>, set<pair<pair<lol, lol>, pair<lol,lol>>>> mp;
lol n, m;
lol dfs(lol i, pair<pair<lol, lol>, lol> x, lol a[])
{
    if (!mp.count(x))
        return 0;
    lol c = 1;
    if (i == m)
        return c;
    for (auto e : mp[x])
    {
        if (e.first.first == i + 1 && e.first.second == a[i] && e.second == i)
        {
            c += dfs(i + 1, e, a);
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
        mp.clear();
        cin >> n >> m;
        lol a[n][m];
        for (lol i = 0; i < n; i++)
        {
            pair<lol, lol> c[m];
            for (lol j = 0; j < m; j++)
            {
                cin >> a[i][j];
                c[j] = {a[i][j], j + 1};
            }
            sort(c, c + m);
            for (lol j = 1; j < m; j++)
            {
                mp[{c[j - 1], {j - 1,}].insert({c[j], j});
            }
            mp[{c[m - 1], m - 1}].size();
        }
        for (lol i = 0; i < n; i++)
        {
            cout << dfs(1, {{1, a[i][0]}, 0}, a[i]) << " ";
        }
        cout << '\n';
    }

    return 0;
}