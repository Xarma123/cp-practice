#include <bits/stdc++.h>
#define lol long long
using namespace std;
map<lol, vector<pair<lol, pair<string, lol>>>> mp;
lol need[200005];
vector<lol> ans;
void dfs(lol c, lol l, lol p)
{
    lol q = ceill(l / (long double)2) - p;
    q = max(q, 0ll);
    for (auto e : mp[c])
    {
        if (e.second.first == " almost protected")
            dfs(e.first, l + 1, p);
        else if (e.second.first == " protected")
            dfs(e.first, l + 1, p + 1);
        q = max(q, need[e.first]);
    }
    need[c] = q;
}
void dfs(lol c, lol ex)
{
    for (auto e : mp[c])
    {
        if (need[e.first] - ex > 0 && e.second.first == " almost protected")
        {
            ans.push_back(e.second.second);
            dfs(e.first, ex + 1);
        }
        else
        {
            dfs(e.first, ex);
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
    for (lol i = 0; i < n - 1; i++)
    {
        lol a, b;
        cin >> a >> b;
        string s;
        getline(cin, s);
        mp[b].push_back({a, {s, i}});
    }
    dfs(1, 0, 0);
    dfs(1, 0);
    cout << ans.size() << endl;
    for (auto e : ans)
        cout << e + 1 << " ";

    return 0;
}