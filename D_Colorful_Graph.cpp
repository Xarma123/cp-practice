#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    lol c[n + 1];
    map<lol, set<lol>> mp;
    for (lol i = 1; i <= n; i++)
    {
        cin >> c[i];
        if (mp[c[i]].size() == 0)
        {
            mp[c[i]].insert(-1);
        }
    }

    while (m--)
    {
        lol a, b;
        cin >> a >> b;
        if (c[a] != c[b])
        {
            mp[c[a]].insert(c[b]);
            mp[c[b]].insert(c[a]);
        }
    }
    lol ans;
    lol v = LONG_LONG_MIN;
    for (auto e : mp)
    {
        if (v < e.second.size())
        {
            v = e.second.size();
            ans = e.first;
        }
    }
    cout << ans;

    return 0;
}