#include <bits/stdc++.h>
using namespace std;
#define lol long long
map<lol, vector<lol>> mp;
lol ans = 0;
lol dp[10000];
lol n;
void dfs(lol c, lol p)
{
    dp[c] = 1;
    for (auto e : mp[c])
    {
        if (e != p)
            dfs(e, c), dp[c] += dp[e];
    }
}
void dfs1(lol c, lol p)
{
    vector<lol> a;
    lol s = 0;
    for (auto e : mp[c])
    {
        if (e != p)
        {
            dfs1(e, c);
            a.push_back(dp[e]);
            s += dp[e];
        }
    }
    bool w[n + 1][a.size()];
    memset(w, false, sizeof(w));
    for (lol i = 0; i < a.size(); i++)
    {
        for (lol j = 0; j <= n; j++)
        {
            if (j == 0)
                w[j][i] = true;
            else if (i == 0)
            {
                w[a[i]][i] = true;
            }
            else
            {
                if (w[j][i - 1])
                    w[j][i] = true;
                if (j - a[i] >= 0 && w[j - a[i]][i - 1])
                    w[j][i] = true;
            }
        }
    }
    lol mx = LONG_LONG_MIN;
    for (lol i = 0; i <= n; i++)
    {
        if (w[i][a.size() - 1])
        {
            mx = max(mx, (s - i) * 1ll * (i));
        }
    }
   
   
    if (mx != LONG_LONG_MIN)
        ans += mx;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (lol i = 2; i <=n ; i++)
    {
        lol a;
        cin >> a;
        mp[i].push_back(a);
        mp[a].push_back(i);
    }
    dfs(1, -1);
    dfs1(1, -1);
    cout << ans;
}