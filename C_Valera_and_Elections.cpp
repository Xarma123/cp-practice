#include <bits/stdc++.h>
#define lol long long
using namespace std;
map<lol, vector<pair<lol, lol>>> mp;
vector<lol> ans;
bool dfs(lol c, lol p)
{
    bool f = false;
    for (auto e : mp[c])
    {
        if (e.first != p)
        {
            if (dfs(e.first, c))
            {
                f = true;
            }
            else if (e.second == 2)
            {
                f = true;
                ans.push_back(e.first);
            }
        }
    }
    return f;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    for (lol i = 0; i < n - 1; i++)
    {
        lol a, b, c;
        cin >> a >> b >> c;
        mp[a].push_back({b, c});
        mp[b].push_back({a, c});
    }
    dfs(1, -1);
    cout << ans.size() << '\n';
    for (auto e : ans)
        cout << e << " ";

    return 0;
}