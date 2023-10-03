#include <bits/stdc++.h>
using namespace std;
#define lol long long
lol solve(lol a[], lol b[], lol c[], vector<lol> v, lol n)
{
    lol ans = 0;
    for (lol i = 0; i < n; i++)
    {
        if (i % 3 == 0)
            ans += a[v[i]];
        else if (i % 3 == 1)
            ans += b[v[i]];
        else
            ans += c[v[i]];
    }
    return ans;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol a[n], b[n], c[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (lol i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    for (lol i = 0; i < n; i++)
    {
        cin >> c[i];
    }
    map<lol, vector<lol>> mp;
    bool ans = true;
    for (lol i = 0; i < n - 1; i++)
    {
        lol x, y;
        cin >> x >> y;
        x--;
        y--;
        mp[x].push_back(y);
        mp[y].push_back(x);
        if (mp[x].size() > 2)
            ans = false;
        if (mp[y].size() > 2)
            ans = false;
    }
    if (!ans)
    {
        cout << -1;
    }
    else
    {
        vector<lol> v;
        bool vis[n];
        memset(vis, false, sizeof(vis));
        for (lol i = 0; i < n; i++)
        {
            if (mp[i].size() == 1)
            {
                v.push_back(i);
                vis[i] = true;
                break;
            }
        }
        while (v.size() < n)
        {
            lol s = v.back();
            for (auto e : mp[s])
            {
                if (!vis[e])
                {
                    vis[e] = true;
                    v.push_back(e);
                }
            }
        }
        lol ff[n];
        lol ans = LONG_LONG_MAX;
        lol ans1 = solve(a, b, c, v, n);
        if (ans > ans1)
        {
            ans = ans1;
            ff[0] = 1;
            ff[1] = 2;
            ff[2] = 3;
        }
        ans1 = solve(a, c, b, v, n);
        if (ans > ans1)
        {
            ans = ans1;
            ff[0] = 1;
            ff[1] = 3;
            ff[2] = 2;
        }
        ans1 = solve(b, a, c, v, n);
        if (ans > ans1)
        {
            ans = ans1;
            ff[0] = 2;
            ff[1] = 1;
            ff[2] = 3;
        }
        ans1 = solve(b, c, a, v, n);
        if (ans > ans1)
        {
            ans = ans1;
            ff[0] = 2;
            ff[1] = 3;
            ff[2] = 1;
        }
        ans1 = solve(c, a, b, v, n);
        if (ans > ans1)
        {
            ans = ans1;
            ff[0] = 3;
            ff[1] = 1;
            ff[2] = 2;
        }
        ans1 = solve(c, b, a, v, n);
        if (ans > ans1)
        {
            ans = ans1;
            ff[0] = 3;
            ff[1] = 2;
            ff[2] = 1;
        }
        for (lol i = 3; i < n; i++)
        {
            ff[i] = ff[(i) % 3];
        }
        cout << ans << '\n';
        lol in[n];
        for (lol i = 0; i < v.size(); i++)
        {
            in[v[i]] = i;
        }
        for (lol i = 0; i < n; i++)
        {
            cout << ff[in[i]] << " ";
        }
        cout << '\n';
    }
}