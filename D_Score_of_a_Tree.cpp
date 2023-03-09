#include <bits/stdc++.h>
#define lol long long
using namespace std;
map<lol, vector<lol>> mp;
lol n, m;
lol pw[200005];
lol ans;
lol dfs(lol c, lol p)
{
    lol v = 0;
    for (auto e : mp[c])
    {
        if (e != p)
        {
            v = max(v, dfs(e, c));
        }
    }
    ans = (ans + (((v + 1) * 1ll * pw[n - 1]) % m)) % m;
    return v + 1;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    m = 1e9 + 7;
    pw[0] = 1;
    for (lol i = 1; i < 200005; i++)
        pw[i] = (pw[i - 1] * 2ll) % m;
    lol t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        mp.clear();
        ans = 0;

        for (lol i = 1; i < n; i++)
        {
            lol a, b;
            cin >> a >> b;
            mp[a].push_back(b);
            mp[b].push_back(a);
        }
        dfs(1, -1);
        cout << ans << '\n';
    }

    return 0;
}