#include <bits/stdc++.h>
using namespace std;
#define lol long long
lol n;
lol a[200005];
vector<lol> mp[200005];
lol sz[200005];
lol dp[200005][22][2];
lol ans[200005];
void dfs(lol c, lol p)
{
    sz[c] = 1;
    for (auto e : mp[c])
    {
        if (e != p)
        {
            dfs(e, c);
            sz[c] += sz[e];
        }
    }
}
void dfs1(lol c, lol p)
{
    lol bache[22][2];
    for (lol k = 0; k < 22; k++)
    {
        bache[k][0] = bache[k][1] = 0;
    }

    for (auto e : mp[c])
    {
        if (e != p)
            dfs1(e, c);
        for (lol k = 0; k < 22; k++)
        {
            bache[k][0] += dp[e][k][0];
            bache[k][1] += dp[e][k][1];
        }
    }

    for (lol k = 0; k < 22; k++)
    {
        if ((a[c] & (1ll << k)))
        {
            dp[c][k][1] = bache[k][1];
            dp[c][k][0] = bache[k][1] + sz[c] * 1ll * (1ll << k);
        }
        else
        {
            dp[c][k][0] = bache[k][0];
            dp[c][k][1] = bache[k][0] + sz[c] * 1ll * (1ll << k);
        }
    }
}
void dfs2(lol c, lol p)
{
    lol val = 0;
    for (lol k = 0; k < 22; k++)
    {
        val += min(dp[c][k][0], dp[c][k][1]);
    }
    ans[c] = val;
    for (auto e : mp[c])
    {
        if (e != p)
        {
            for (lol k = 0; k < 22; k++)
            {
                if ((a[c] & (1ll << k)))
                {
                    dp[c][k][1] -= dp[e][k][1];
                    dp[c][k][0] -= dp[e][k][1] + sz[e] * 1ll * (1ll << k);
                }
                else
                {
                    dp[c][k][0] -= dp[e][k][0];
                    dp[c][k][1] -= dp[e][k][0] + sz[e] * 1ll * (1ll << k);
                }
            }
            sz[c] -= sz[e];
            for (lol k = 0; k < 22; k++)
            {
                if ((a[e] & (1ll << k)))
                {
                    dp[e][k][1] += dp[c][k][1];
                    dp[e][k][0] += dp[c][k][1] + sz[c] * 1ll * (1ll << k);
                }
                else
                {
                    dp[e][k][0] += dp[c][k][0];
                    dp[e][k][1] += dp[c][k][0] + sz[c] * 1ll * (1ll << k);
                }
            }
            sz[e] += sz[c];

            dfs2(e, c);
            swap(e, c);
            for (lol k = 0; k < 22; k++)
            {
                if ((a[c] & (1ll << k)))
                {
                    dp[c][k][1] -= dp[e][k][1];
                    dp[c][k][0] -= dp[e][k][1] + sz[e] * 1ll * (1ll << k);
                }
                else
                {
                    dp[c][k][0] -= dp[e][k][0];
                    dp[c][k][1] -= dp[e][k][0] + sz[e] * 1ll * (1ll << k);
                }
            }
            sz[c] -= sz[e];
            for (lol k = 0; k < 22; k++)
            {
                if ((a[e] & (1ll << k)))
                {
                    dp[e][k][1] += dp[c][k][1];
                    dp[e][k][0] += dp[c][k][1] + sz[c] * 1ll * (1ll << k);
                }
                else
                {
                    dp[e][k][0] += dp[c][k][0];
                    dp[e][k][1] += dp[c][k][0] + sz[c] * 1ll * (1ll << k);
                }
            }
            sz[e] += sz[c];
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
        cin >> n;
        for (lol i = 1; i <= n; i++)
        {
            cin >> a[i];
            sz[i] = 0;
        }
        for (lol i = 1; i <= n; i++)
        {
            mp[i].clear();
            ans[i] = 0;
            for (lol k = 0; k < 22; k++)
            {
                dp[i][k][0] = dp[i][k][1] = 0;
            }
        }
        for (lol i = 0; i < n - 1; i++)
        {
            lol x, y;
            cin >> x >> y;
            mp[x].push_back(y);
            mp[y].push_back(x);
        }
        dfs(1, -1);
        dfs1(1, -1);
        dfs2(1, -1);
        for (lol i = 0; i < n; i++)
        {
            cout << ans[i + 1] << ' ';
        }
        cout << '\n';
    }
}