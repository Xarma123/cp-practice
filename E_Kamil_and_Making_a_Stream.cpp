#include <bits/stdc++.h>
using namespace std;
#define lol long long
lol n;
vector<lol> mp[100005];
lol x[100005];
lol m = 1e9 + 7;
lol ans = 0;
map<lol, lol> dp[100005];
void dfs(lol c, lol p)
{

    dp[c][x[c]]++;
    for (auto e : dp[p])
    {
        lol g = __gcd(x[c], e.first);
        dp[c][g] += e.second;
        dp[c][g] %= m;
    }
    for (auto e : dp[c])
    {
        ans += (e.first * 1ll * e.second) % m;
        ans %= m;
    }
    for (auto e : mp[c])
    {
        if (e != p)
        {
            dfs(e, c);
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (lol i = 1; i <= n; i++)
    {
        cin >> x[i];
    }
    for (lol i = 0; i < n - 1; i++)
    {
        lol a, b;
        cin >> a >> b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    dfs(1, 0);
    cout << ans;
}