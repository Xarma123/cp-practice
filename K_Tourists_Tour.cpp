#include <bits/stdc++.h>
using namespace std;
#define lol long
vector<lol> mp[1000005];
map<lol, lol> col;
void dfs(lol c)
{
    set<lol> all;
    for (auto e : mp[c])
    {
        if (col.count(e))
        {
            all.insert(col[e]);
        }
    }
    lol g = 1;
    while (all.count(g))
        g++;
    col[c] = g;
    for (auto e : mp[c])
    {
        if (!col.count(e))
        {
            dfs(e);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("tour.in", "r", stdin);
    lol t;
    cin >> t;
    while (t--)
    {
        col.clear();
        lol n;
        cin >> n;
        lol h[n];
        for (lol i = 0; i < n; i++)
        {
            mp[i].clear();
            cin >> h[i];
        }
        lol nx[n], pv[n];
        stack<lol> x;
        x.push(-1);
        for (lol i = 0; i < n; i++)
        {
            while (x.top() != -1 && h[x.top()] < h[i])
            {
                nx[x.top()] = i;
                x.pop();
            }
            pv[i] = x.top();
            x.push(i);
        }
        while (x.top() != -1)
        {
            nx[x.top()] = n;
            x.pop();
        }
        for (lol i = 0; i < n; i++)
        {
            if (pv[i] != -1)
            {
                mp[i].push_back(pv[i]);
                mp[pv[i]].push_back(i);
            }
            if (nx[i] != n)
            {
                mp[i].push_back(nx[i]);
                mp[nx[i]].push_back(i);
            }
        }
        lol ans = 0;
        for (lol i = 0; i < n; i++)
        {
            if (!col.count(i))
            {
                dfs(i);
            }
            ans = max(ans, col[i]);
        }
        cout << ans << '\n';
        for (lol i = 0; i < n; i++)
        {
            cout << col[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
