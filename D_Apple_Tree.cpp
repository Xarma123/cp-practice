#include <bits/stdc++.h>
using namespace std;
#define lol long long
map<lol, vector<lol>> mp;
lol dp[200005];
void dfs(lol u, lol p)
{
    if (mp[u].size() == 1 && p != -1)
    {
        dp[u] = 1;
        return;
    }
    for (auto e : mp[u])
    {
        if (e != p)
        {
            dfs(e, u);
            dp[u] += dp[e];
        }
    }
}
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        mp.clear();
        memset(dp, 0, sizeof(dp));
        for (lol i = 0; i < n - 1; i++)
        {
            lol a, b;
            cin >> a >> b;
            mp[a].push_back(b);
            mp[b].push_back(a);
        }
        dfs(1, -1);
        lol q;
        cin >> q;
        while (q--)
        {
            lol x, y;
            cin >> x >> y;
            cout << dp[x] * 1ll * dp[y] << '\n';
        }
    }
}