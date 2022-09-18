#include <bits/stdc++.h>
#define lol long long
using namespace std;
map<lol, vector<lol>> mp;
map<lol, pair<lol, lol>> b;
lol ans;
lol dfs(lol c, lol p)
{
    bool f = false;
    lol co = 0;
    lol sum = 0;
    for (auto e : mp[c])
    {
        if (e != p)
        {
            co++;
            sum += dfs(e, c);
        }
    }
    if (co == 0)
    {
        ans++;
        return b[c].second;
    }
    if (sum >= b[c].first)
    {
        return min(sum, b[c].second);
    }
    ans++;
    return b[c].second;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;

    while (t--)
    {
        mp.clear();
        b.clear();
        ans = 0;
        lol n;
        cin >> n;
        for (lol i = 2; i <= n; i++)
        {
            lol p;
            cin >> p;
            mp[p].push_back(i);
            mp[i].push_back(p);
        }
        for (lol i = 1; i <= n; i++)
        {
            lol l, r;
            cin >> l >> r;
            b[i] = {l, r};
        }
        dfs(1, 0);
        cout << ans << endl;
    }

    return 0;
}