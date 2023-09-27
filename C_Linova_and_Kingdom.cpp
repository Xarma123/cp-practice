#include <bits/stdc++.h>
using namespace std;
#define lol long long
map<lol, vector<lol>> mp;
map<lol, lol> sz;
map<lol, lol> d;
void dfs(lol c, lol p, lol l)
{
    sz[c] = 1;
    d[c] = l;
    for (auto e : mp[c])
    {
        if (e != p)
        {
            dfs(e, c, l + 1);
            sz[c] += sz[e];
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, k;
    cin >> n >> k;
    map<lol, lol> in;
    for (lol i = 0; i < n - 1; i++)
    {
        lol a, b;
        cin >> a >> b;
        mp[a].push_back(b);
        mp[b].push_back(a);
        in[a]++;
        in[b]++;
    }
    in[1]++;
    for (lol i = 1; i <= n; i++)
    {
        
    }
}