#include <bits/stdc++.h>
#define lol long long
using namespace std;

map<lol, vector<lol>> mp;
lol base;
bool dfs(lol nd, lol col, lol c[])
{
    c[nd] = col + base;
    for (auto e : mp[nd])
    {
        if (c[e] == -1)
        {
            if (!dfs(e, 1 - col, c))
                return false;
        }
        else if (c[e] == c[nd])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    mp.clear();
    base = -2;
    lol n, m;
    cin >> n >> m;
    while (m--)
    {
        lol a, b;
        cin >> a >> b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    lol c[n + 1];
    for (lol i = 0; i <= n; i++)
    {
        c[i] = -1;
    }

    bool ans = true;

    for (lol i = 1; i <= n; i++)
    {
        if (c[i] == -1)
        {
            base += 2;
            ans &= dfs(i, 0, c);
        }
    }

    if (ans)
    {
        map<lol, lol> f;
        for (lol i = 1; i <= n; i++)
        {
            f[c[i]]++;
        }
        lol tot = 0;
        for (lol i = 1; i <= n; i++)
        {
            if (c[i] % 2 == 0)
            {
                lol x = c[i] + 1;
                tot += f[x] - mp[i].size();
                tot += n - f[x] - f[c[i]];
            }
            else
            {
                lol x = c[i] - 1;
                tot += f[x] - mp[i].size();
                tot += n - f[x] - f[c[i]];
            }
        }
        cout << tot / 2ll;
    }
    else
        cout << 0ll;

    return 0;
}