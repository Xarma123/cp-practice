#include <bits/stdc++.h>
#define lol long long
using namespace std;
//
lol n, k;
lol ans;
void dfs(lol c, lol p, vector<lol> mp[], vector<vector<lol>> &dp)
{
    dp[c][0] = 1;
    for (auto e : mp[c])
    {
        if (e != p)
        {
            dfs(e, c, mp, dp);
            for (lol i = 1; i <= k; i++)
            {
                dp[c][i] += dp[e][i - 1];
            }
        }
    }
}
void dfs1(lol c, lol p, vector<lol> mp[], vector<vector<lol>> &dp)
{
    ans += dp[c][k];
    for (auto e : mp[c])
    {
        if (e != p)
        {
            for (lol i = 1; i <= k; i++)
            {
                dp[c][i] -= dp[e][i - 1];
            }
            for (lol i = 1; i <= k; i++)
            {
                dp[e][i] += dp[c][i - 1];
            }
            dfs1(e, c, mp, dp);
            for (lol i = 1; i <= k; i++)
            {
                dp[e][i] -= dp[c][i - 1];
            }
            for (lol i = 1; i <= k; i++)
            {
                dp[c][i] += dp[e][i - 1];
            }
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    vector<lol> mp[n + 1];
    ans = 0;
    vector<vector<lol>> dp(n + 1, vector<lol>(k + 1, 0));
    for (lol i = 0; i < n - 1; i++)
    {
        lol a, b;
        cin >> a >> b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    dfs(1, 0, mp, dp);
    dfs1(1, 0, mp, dp);
    cout << ans / 2 << endl;
    return 0;
}