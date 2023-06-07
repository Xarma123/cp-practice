#include <bits/stdc++.h>
using namespace std;
#define lol long long
map<lol, vector<pair<lol, lol>>> mp;
lol co[200005];
bool ans;
vector<lol> f;
void dfs(lol c, lol p)
{
    if (!ans)
        return;
    lol l = co[c];
    for (auto e : mp[c])
    {
        if (!ans)
            return;
        if (e.first != p)
        {
            dfs(e.first, c);
            if (l == co[c])
            {
                f.push_back(e.second + 1);
            }
            l = co[c];
            if (co[c] > 2)
            {
                ans = false;
                return;
            }
        }
    }

    if (!ans)
        return;
    if (co[c] == 0)
    {
        if (p < 0)
        {
            ans = false;
            return;
        }
        co[p]++;
    }
    else if (co[c] == 1)
    {
        if (p < 0)
        {
            ans = false;
            return;
        }
        co[p] += 2;
    }
}
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        mp.clear();
        ans = true;
        f.clear();
        memset(co, 0, sizeof(co));
        for (lol i = 0; i < n - 1; i++)
        {
            lol a, b;
            cin >> a >> b;
            mp[a].push_back({b, i});
            mp[b].push_back({a, i});
        }
        dfs(1, -1);
        if (!ans)
            cout << -1 << '\n';
        else
        {
            cout << f.size() << '\n';
            for (auto e : f)
                cout << e << " ";
            cout << '\n';
        }
    }
}