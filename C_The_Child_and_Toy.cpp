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
    lol v[n + 1];
    pair<lol, lol> a[n + 1];
    for (lol i = 1; i <= n; i++)
    {
        cin >> v[i];
        a[i] = {v[i], i};
    }
    sort(a, a + n + 1);
    map<lol, vector<lol>> mp;
    while (m--)
    {
        lol q, x;
        cin >> q >> x;
        mp[q].push_back(x);
        mp[x].push_back(q);
    }
    set<lol> r;
    lol ans = 0;
    for (lol i = n; i >= 1; i--)
    {
        for (auto e : mp[a[i].second])
        {
            if (!r.count(e))
                ans += v[e];
        }
        r.insert(a[i].second);
    }
    cout << ans;

    return 0;
}