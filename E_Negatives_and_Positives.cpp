#include <bits/stdc++.h>
using namespace std;
#define lol long long
map<lol, vector<pair<lol, lol>>> mp;
lol dp[100005];
void dfs(lol c, lol p)
{
    dp[c] = 0;
    for (auto e : mp[c])
    {
        if (e.first != p)
        {
            if (e.second == -1)
                dp[c]++;
            dfs(e.first, c);
            dp[c] += dp[e.first];
        }
    }
    
}
lol ans = LONG_LONG_MAX;
void dfs1(lol c, lol p, lol u)
{
   
    ans = min(ans, dp[c] + u);
    for (auto e : mp[c])
    {
        if (e.first != p)
        {
            lol v = dp[c] + u - dp[e.first];
            if (e.second == -1)
                v--;
            if (e.second != -1)
                v++;
            dfs1(e.first, c, v);
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
    lol fr[n - 1], to[n - 1];
    for (lol i = 0; i < n - 1; i++)
    {
        cin >> fr[i];
    }
    for (lol i = 0; i < n - 1; i++)
    {
        cin >> to[i];
    }
    for (lol i = 0; i < n - 1; i++)
    {
        mp[fr[i]].push_back({to[i], 1});
        mp[to[i]].push_back({fr[i], -1});
    }
    dfs(1, -1);
    dfs1(1, -1, 0);
    cout << ans;
}