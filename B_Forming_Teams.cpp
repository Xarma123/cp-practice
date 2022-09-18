#include <bits/stdc++.h>
#define lol long long
using namespace std;
map<lol, vector<lol>> mp;
lol dfs(lol cur, lol col[], lol c)
{
    col[cur] = c;
    lol r = 0;

    for (auto e : mp[cur])
    {
        if (col[e] == 0)
        {
            r += dfs(e, col, 3 - c);
        }
        else if (col[e] == c)
        {
            r++;
        }
    }
    col[cur] = 3;
    return r;
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
    lol col[n + 1];
    memset(col, 0, sizeof(col));
    lol ans = 0;
    for (lol i = 1; i <= n; i++)
    {
        if (col[i] == 0)
            ans += dfs(i, col, 1);
    }
    if ((n - ans) % 2 != 0)
        ans++;
    cout << ans;

    return 0;
}