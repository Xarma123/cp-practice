#include <bits/stdc++.h>
using namespace std;
#define lol long long
bool marked[200005];
vector<lol> tree[200005];
lol dp[200005];
lol ans = LONG_LONG_MAX;
void dfs(lol c, lol p)
{
    dp[c] = LONG_LONG_MIN;
    if (marked[c] == true)
    {
        dp[c] = 0ll;
    }
    for (auto e : tree[c])
    {
        if (e != p)
        {
            dfs(e, c);
            dp[c] = max(dp[c], 1 + dp[e]);
        }
    }
}
void dfs1(lol c, lol p)
{
    // cout << endl;
    // cout << c << endl;
    // cout << dp[c] << endl;
    ans = min(ans, dp[c]);
    lol mx1 = LONG_LONG_MIN;
    lol mx2 = LONG_LONG_MIN;
    if (marked[c])
    {
        mx1 = 0;
    }
    for (auto e : tree[c])
    {
        
            if (mx1 <= dp[e] + 1)
            {
                mx2 = mx1;
                mx1 = dp[e] + 1;
            }
            else if (mx2 < dp[e] + 1)
                mx2 = dp[e] + 1;
        
    }

    for (auto e : tree[c])
    {
        if (e != p)
        {
            if (dp[e] + 1 == mx1)
            {
                dp[c] = mx2;
            }
            dp[e] = max(dp[e], dp[c] + 1);
            dfs1(e, c);
            swap(e, c);
            if (dp[e] + 1 == mx1)
            {
                dp[c] = mx2;
            }
            dp[e] = max(dp[e], dp[c] + 1);
            swap(e, c);
        }
    }
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
        lol n, k;
        cin >> n >> k;
        for (lol i = 1; i <= n; i++)
        {
            marked[i] = false;
            tree[i].clear();
            dp[i] = 0;
        }
        ans = LONG_LONG_MAX;
        for (lol i = 0; i < k; i++)
        {
            lol v;
            cin >> v;
            marked[v] = true;
        }
        for (lol i = 0; i < n - 1; i++)
        {
            lol x, y;
            cin >> x >> y;
            tree[x].push_back(y);
            tree[y].push_back(x);
        }
        dfs(1, -1);
        dfs1(1, -1);
        cout << ans << '\n';
    }
}