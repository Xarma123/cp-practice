#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m, k;
    cin >> n >> m >> k;
    lol a[k];
    for (lol i = 0; i < k; i++)
    {
        cin >> a[i];
    }
    vector<lol> mp[n + 1];
    while (m--)
    {
        lol l, r;
        cin >> l >> r;
        mp[l].push_back(r);
        mp[r].push_back(l);
    }
    lol d1[n + 1];
    memset(d1, -1, sizeof(d1));
    queue<lol> q;
    q.push(1);
    d1[1] = 0;
    while (!q.empty())
    {
        lol v = q.front();
        q.pop();
        for (auto e : mp[v])
        {
            if (d1[e] == -1)
            {
                d1[e] = d1[v] + 1;
                q.push(e);
            }
        }
    }
    lol d2[n + 1];
    memset(d2, -1, sizeof(d2));
    q.push(n);
    d2[n] = 0;
    while (!q.empty())
    {
        lol v = q.front();
        q.pop();
        for (auto e : mp[v])
        {
            if (d2[e] == -1)
            {
                d2[e] = d2[v] + 1;
                q.push(e);
            }
        }
    }
    pair<lol, lol> b[k];
    for (lol i = 0; i < k; i++)
    {
        b[i].first = d1[a[i]] - d2[a[i]];
        b[i].second = d2[a[i]];
    }
    sort(b, b + k);
    lol mx;
    lol ans = LONG_LONG_MIN;
    for (lol i = k - 1; i >= 0; i--)
    {
        if (i == k - 1)
        {
            mx = b[i].second;
        }
        else
        {
            ans = max(ans, mx + b[i].first + b[i].second);
            mx = max(mx, b[i].second);
        }
    }
    ans = min(ans + 1, d1[n]);
    cout << ans;
}