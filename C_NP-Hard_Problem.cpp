#include <bits/stdc++.h>
#define lol long long
using namespace std;
map<lol, vector<lol>> mp;
lol vis[100001];
bool dfs(lol c, lol give)
{
    vis[c] = give;
    for (auto e : mp[c])
    {
        if (vis[e] == 0)
        {
            if (!dfs(e, 3 - give))
                return false;
        }
        else if (vis[e] == give)
            return false;
    }
    return true;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    while (m--)
    {
        lol a, b;
        cin >> a >> b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    bool ans = true;
    for (lol i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
            ans &= dfs(i, 1);
    }
    if (ans)
    {
        vector<lol> o, b;
        for (lol i = 1; i <= n; i++)
        {
            if (vis[i] == 1)
            {
                o.push_back(i);
            }
            else
            {
                b.push_back(i);
            }
        }
        cout << o.size() << endl;
        for (auto e : o)
            cout << e << " ";
        cout << endl;
        cout << b.size() << endl;
        for (auto e : b)
            cout << e << " ";
        cout << endl;
    }
    else
        cout << -1;

    return 0;
}