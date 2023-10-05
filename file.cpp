#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol ind[n];
    memset(ind, 0, sizeof(ind));
    lol m;
    cin >> m;
    map<lol, vector<lol>> mp;
    while (m--)
    {
        lol a, b;
        cin >> a >> b;
        a--;
        b--;
        ind[a]++;
        ind[b]++;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    queue<lol> q;
    for (lol i = 0; i < n; i++)
    {
        if (ind[i] == 1)
            q.push(i);
    }
    while (!q.empty())
    {
        lol c = q.front();
        q.pop();
        if (ind[c] != 1)
            continue;
        for (auto e : mp[c])
        {
            ind[e]--;
            if (ind[e] == 1)
                q.push(e);
        }
        ind[c] = LONG_LONG_MAX;
    }
    lol ans = 0;
    for (lol i = 0; i < n; i++)
    {
        if (ind[i] <= 0)
            ans++;
    }
    cout << ans;
}