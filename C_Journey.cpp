#include <bits/stdc++.h>
#define lol long double
using namespace std;
map<lol, vector<lol>> mp;
lol ans = 0;
void dfs(lol c, lol p, lol d, lol q)
{
    // cout << c << " " << q << " " << d << endl;
    if (mp[c].size() == 1)
    {

        ans += q * d;
    }
    for (auto e : mp[c])
    {
        if (e != p)
        {
            dfs(e, c, d + 1, q * (1 / (long double)(mp[c].size() - 1 + (p == -1))));
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
    for (int i = 1; i < n; i++)
    {
        lol a, b;
        cin >> a >> b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    dfs(1, -1, 0, 1);
    cout << fixed << setprecision(9) << ans;
}