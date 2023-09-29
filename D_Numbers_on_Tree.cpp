#include <bits/stdc++.h>
using namespace std;
#define lol long long
vector<lol> mp[2005];
lol sz[2005];
lol cz[2005];
lol ans[2005];
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
bool f = true;
void dfs(lol c, lol p, vector<lol> v)
{
    if (cz[c] > sz[c] - 1)
        f = false;
    if (!f)
        return;
    ans[c] = v[cz[c]];
    v.erase(v.begin() + cz[c]);
    for (auto e : mp[c])
    {
        if (e != p)
        {
            vector<lol> a;
            while (a.size() < sz[e])
            {
                a.push_back(v.back());
                v.pop_back();
            }
            reverse(a.begin(), a.end());
            dfs(e, c, a);
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol root;
    for (lol i = 1; i <= n; i++)
    {
        lol p;
        cin >> p;
        if (p)
        {
            mp[i].push_back(p);
            mp[p].push_back(i);
        }
        else
            root = i;
        cin >> cz[i];
    }
    dfs(root, 0);
    vector<lol> v;
    for (lol i = 1; i <= n; i++)
    {
        v.push_back(i);
    }
    dfs(root, 0, v);
    if (f)
    {
        cout << "YES\n";
        for (lol i = 1; i <= n; i++)
        {
            cout << ans[i] << " ";
        }
    }
    else
    {
        cout << "NO\n";
    }
}