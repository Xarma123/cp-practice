#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    map<lol, vector<lol>> mp;
    map<lol, lol> ind, ind1;
    map<lol, lol> outd;
    while (m--)
    {
        lol a, b;
        cin >> a >> b;
        mp[a].push_back(b);
        ind[b]++;
        ind1[b]++;
        outd[a]++;
    }
    vector<lol> topo;
    queue<lol> q;
    for (lol i = 1; i <= n; i++)
    {
        if (ind[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        lol f = q.front();
        q.pop();
        topo.push_back(f);
        for (auto e : mp[f])
            if (--ind[e] == 0)
                q.push(e);
    }
    lol dp[n + 1];
    memset(dp, 0, sizeof(dp));
    for (lol i = n - 1; i >= 0; i--)
    {
        if (ind1[topo[i]] > 1 && outd[topo[i]] > 1)
        {
            for (auto e : mp[topo[i]])
            {
                if (ind1[e] > 1 && outd[e] > 1)
                    dp[topo[i]] = max(dp[topo[i]], dp[e] + 1);
            }
        }
    }
    for (lol i = n - 1; i >= 0; i--)
    {
        if (ind1[topo[i]] > 1 && outd[topo[i]] > 1)
        {
            for (auto e : mp[topo[i]])
            {
                if (ind1[e] > 1)
                    dp[topo[i]] = max(dp[topo[i]], dp[e] + 1);
            }
        }
    }
    for (lol i = n - 1; i >= 0; i--)
    {
        if (outd[topo[i]] > 1)
        {
            for (auto e : mp[topo[i]])
            {
                if (ind1[e] > 1)
                    dp[topo[i]] = max(dp[topo[i]], dp[e] + 1);
            }
        }
    }
    lol ans = 1;
    for (lol i = 1; i <= n; i++)
    {
        ans = max(ans, dp[i] + 1);
    }
    cout << ans;

    return 0;
}