#include <bits/stdc++.h>
using namespace std;
//a
#define lol long long
vector<pair<lol, char>> mp[100005];
lol color[100005];
vector<lol> o, z;
bool ans = true;
void dfs(lol c, lol g)
{
    if (g == 0)
    {
        z.push_back(c);
    }
    else
        o.push_back(c);
    color[c] = g;
    for (auto e : mp[c])
    {
        if (color[e.first] == -1)
        {
            if (e.second == 'R')
            {
                dfs(e.first, 1 - g);
            }
            else
                dfs(e.first, g);
        }
        else if (color[e.first] == g && e.second == 'R')
        {
            ans = false;
        }
        else if (color[e.first] != g && e.second == 'B')
        {
            ans = false;
        }
    }
}
void dfs1(lol c, lol g)
{
    if (g == 0)
    {
        z.push_back(c);
    }
    else
        o.push_back(c);
    color[c] = g;
    for (auto e : mp[c])
    {
        if (color[e.first] == -1)
        {
            if (e.second == 'B')
            {
                dfs1(e.first, 1 - g);
            }
            else
                dfs1(e.first, g);
        }
        else if (color[e.first] == g && e.second == 'B')
        {
            ans = false;
        }
        else if (color[e.first] != g && e.second == 'R')
        {
            ans = false;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    while (m--)
    {
        lol a, b;
        cin >> a >> b;
        char c;
        cin >> c;
        mp[a].push_back({b, c});
        mp[b].push_back({a, c});
    }
    for (lol i = 1; i <= n; i++)
    {
        color[i] = -1;
    }
    vector<lol> r;

    for (lol i = 1; i <= n; i++)
    {
        if (color[i] == -1)
        {
            o.clear();
            z.clear();
            dfs(i, 0);
            if (o.size() < z.size())
            {
                for (auto e : o)
                    r.push_back(e);
            }
            else
            {
                for (auto e : z)
                    r.push_back(e);
            }
        }
    }
    if (!ans)
    {
        ans = true;
        r.resize(n + 10);
    }

    for (lol i = 1; i <= n; i++)
    {
        color[i] = -1;
    }
    vector<lol> b;

    for (lol i = 1; i <= n; i++)
    {
        if (color[i] == -1)
        {
            o.clear();
            z.clear();
            dfs1(i, 0);
            if (o.size() < z.size())
            {
                for (auto e : o)
                    b.push_back(e);
            }
            else
            {
                for (auto e : z)
                    b.push_back(e);
            }
        }
    }
    if (!ans)
    {
        ans = true;
        b.resize(n + 10);
    }
    if (r.size() <= n || b.size() <= n)
    {
        if (r.size() > b.size())
            r = b;
        cout << r.size() << '\n';
        for (auto e : r)
            cout << e << ' ';
    }
    else
        cout << -1;

    return 0;
}
