#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol a, b, c, d, e, f;
set<pair<lol, lol>> p;
lol m = 998244353;
map<pair<lol, pair<lol, lol>>, lol> mp;
lol dfs(lol x, lol y, lol n)
{
    if (mp.count({x, {y, n}}))
        return mp[{x, {y, n}}];
    if (p.count({x, y}))
        return mp[{x, {y, n}}] = 0;
    if (n == 0)
        return mp[{x, {y, n}}] = 1;
    lol ans = 0;

    ans += dfs(x + a, y + b, n - 1);
    ans %= m;

    ans += dfs(x + c, y + d, n - 1);
    ans %= m;

    ans += dfs(x + e, y + f, n - 1);
    ans %= m;
    return mp[{x, {y, n}}] = ans;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    cin >> a >> b >> c >> d >> e >> f;
    while (m--)
    {
        lol a1, b1;
        cin >> a1 >> b1;
        p.insert({a1, b1});
    }
    cout << dfs(0, 0, n);

    return 0;
}