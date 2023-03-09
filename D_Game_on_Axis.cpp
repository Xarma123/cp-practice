#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol n;
lol dfs(lol c, lol dp[], lol a[])
{
    if (dp[c] != -1)
        return dp[c];
    dp[c] = 0;
    if (c + a[c] < 0 || c + a[c] >= n)
        return dp[c] = 1;
    return dp[c] = dfs(a[c] + c, dp, a);
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
        lol a[n];
        for (lol i = 0; i < n; i++)
            cin >> a[i];
        lol dp[n];
        memset(dp, -1, sizeof(dp));
        for (lol i = 0; i < n; i++)
        {
            if (dp[i] == -1)
            {
                dp[i] = dfs(i, dp, a);
            }
        }

        if (dp[0] == 0ll)
        {
            lol x = 0;
            for (lol i = 0; i < n; i++)
            {
                x += dp[i];
            }
            bool vis[n];
            memset(vis, false, sizeof(vis));
            lol i = 0;
            lol c = 1;
            vis[i] = true;
            while (!vis[i + a[i]])
            {
                i = a[i] + i;
                vis[i] = true;
                c++;
            }
            cout << c * 1ll * (x + n + 1) << '\n';
        }
        else
        {

            lol x = 0;
            for (lol i = 0; i < n; i++)
            {
                x += dp[i];
            }
            bool vis[n];
            memset(vis, false, sizeof(vis));
            lol i = 0;
            lol q[n];
            memset(q, 0, sizeof(q));
            map<lol, lol> ind;
            for (lol i = 0; i < n; i++)
            {
                if (dp[i])
                {
                    if (a[i] + i >= 0 && a[i] + i < n)
                    {
                        ind[a[i] + i]++;
                    }
                }
            }
            queue<lol> qe;
            for (lol i = 0; i < n; i++)
            {
                if (dp[i])
                {
                    if (ind[i] == 0)
                        qe.push(i);
                }
            }
            while (!qe.empty())
            {
                lol v = qe.front();
                q[v]++;
                qe.pop();
                if (a[v] + v >= 0 && a[v] + v < n)
                {
                    ind[a[v] + v]--;
                    q[a[v] + v] += q[v];
                    if (ind[a[v] + v] == 0)
                    {
                        qe.push(a[v] + v);
                    }
                }
            }

            lol c = 1;
            memset(vis, false, sizeof(vis));
            vis[i] = true;
            lol ans = (n + 1);
            ans += x - q[i];

            while ((i + a[i] >= 0 && i + a[i] < n) && !vis[i + a[i]])
            {
                i = a[i] + i;
                vis[i] = true;
                ans += (n + 1);
                ans += x - q[i];
                c++;
            }
            ans += (n - c) * 1ll * (2ll * n + 1);
            cout << ans << '\n';
        }
    }

    return 0;
}