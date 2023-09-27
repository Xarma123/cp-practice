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
    map<lol, vector<lol>> mp;
    vector<pair<lol, lol>> ed;
    lol nod = -1;
    for (lol i = 0; i < n - 1; i++)
    {
        lol a, b;
        cin >> a >> b;
        ed.push_back({a, b});
        mp[a].push_back(b);
        mp[b].push_back(a);
        if (mp[a].size() >= 3)
        {
            nod = a;
        }
        if (mp[b].size() >= 3)
        {
            nod = b;
        }
    }
    if (nod == -1)
    {
        for (lol i = 0; i < n - 1; i++)
        {
            cout << i << endl;
        }
    }
    else
    {
        lol ans[n - 1];
        memset(ans, -1, sizeof(ans));
        lol c = 0;
        for (lol i = 0; i < n - 1; i++)
        {
            if (ed[i].first == nod || ed[i].second == nod)
            {
                ans[i] = (c++);
                if (c > 2)
                    break;
            }
        }
        for (lol i = 0; i < n - 1; i++)
        {
            if (ans[i] == -1)
            {
                ans[i] = (c++);
            }
            cout << ans[i] << "\n";
        }
    }
}