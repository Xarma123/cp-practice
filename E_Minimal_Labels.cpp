#include <bits/stdc++.h>
using namespace std;
#define lol long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    map<lol, vector<lol>> mp;
    map<lol, lol> ind;
    while (m--)
    {
        lol x, y;
        cin >> x >> y;
        mp[y].push_back(x);
        ind[x]++;
    }
    set<lol> x;
    for (lol i = 1; i <= n; i++)
    {
        if (ind[i] == 0)
            x.insert(i);
    }
    vector<lol> a;
    while (!x.empty())
    {
        lol v = (*x.rbegin());
        x.erase(v);
        a.push_back(v);
        for (auto e : mp[v])
        {
            ind[e]--;
            if (ind[e] == 0)
                x.insert(e);
        }
    }
    reverse(a.begin(),a.end());
    lol ans[n + 1];
    for (lol i = 0; i < a.size(); i++)
    {
        ans[a[i]] = i + 1;
    }
    for (lol i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";  
    }

    return 0;
}