#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol n, m, k;
lol a[200005];
vector<lol> ed[200005];
bool solve(lol mx)
{
    vector<lol> mp[n + 1];
    lol ind[n + 1];
    lol dp[n + 1];
    memset(ind, 0, sizeof(ind));
    memset(dp, 0, sizeof(dp));
    for (lol i = 1; i <= n; i++)
    {
        if (a[i] <= mx)
        {
            for (auto e : ed[i])
            {
                if (a[e] <= mx)
                {
                    mp[i].push_back(e);
                    ind[e]++;
                }
            }
        }
    }
    queue<lol> q;
    for (lol i = 1; i <= n; i++)
    {
        if (ind[i] == 0)
            q.push(i);
    }
    lol c = 0;
    lol ans = 0;
    while (!q.empty())
    {
        c++;

        lol u = q.front();
        q.pop();
        for (auto e : mp[u])
        {
            if (--ind[e] == 0)
                q.push(e);
            dp[e] = max(dp[e], dp[u] + 1);
            ans = max(ans, dp[e]);
        }
    }

    if (c == n)
    {
        return ans >= k;
    }
    else
        return true;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;
    k--;
    lol mn = 1e10;
    for (lol i = 1; i <= n; i++)
        cin >> a[i], mn = min(mn, a[i]);
    while (m--)
    {
        lol f, s;
        cin >> f >> s;
        ed[f].push_back(s);
    }
    if (k == 0)
        cout << mn;
    else
    {
        lol st = 0, e = 1e10;
        while (st != e - 1)
        {
            m = (st + e) / 2;
            if (m == (long long)1e10)
            {
                e = m;
            }
            else if (m == 0)
                st = m;
            else if (solve(m))
                e = m;
            else
                st = m;
        }
        if (e == (long long)1e10)
            e = -1;
        cout << e;
    }
    return 0;
}