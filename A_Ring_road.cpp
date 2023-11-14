#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    map<lol, vector<lol>> mp;
    map<pair<lol, lol>, lol> mp1;
    lol N = n;
    while (n--)
    {
        lol a, b, c;
        cin >> a >> b >> c;
        mp[a].push_back(b);
        mp[b].push_back(a);
        mp1[{a, b}] = 0;
        mp1[{b, a}] = c;
    }
    n = N;
    vector<lol> order;
    bool vis[n + 1];
    memset(vis, false, sizeof(vis));
    lol c = 1;
    while (!vis[c])
    {
        order.push_back(c);
        vis[c] = true;
        for (auto i : mp[c])
        {
            if (!vis[i])
            {
                c = i;
            }
        }
    }
    lol ans1 = 0;
    for (lol i = 0; i < n; i++)
    {
        ans1 += mp1[{order[i], order[(i + 1) % n]}];
    }
    lol ans2 = 0;
    for (lol i = 1; i < n; i++)
    {
        ans2 += mp1[{order[i], order[i - 1]}];
    }
    ans2 += mp1[{order[0], order[n - 1]}];
    cout << min(ans2, ans1);

    return 0;
}
