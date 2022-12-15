#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, k;
    cin >> n >> k;
    set<pair<lol, lol>> x;
    for (lol i = 0; i < n; i++)
    {
        lol v;
        cin >> v;
        x.insert({v, i});
    }
    map<lol, set<lol>> level;
    vector<vector<lol>> edge;
    map<lol, lol> nhb;
    bool ans = true;
    while (!x.empty() && ans)
    {
        pair<lol, lol> a = (*x.begin());
        x.erase(x.begin());
        lol l = a.first;
        lol v = a.second;
        if (l == 0)
        {
            if (level[l].size())
            {
                ans = false;
                break;
            }
            level[l].insert(v);
        }
        else
        {
            if (level[l - 1].size())
            {
                lol u = (*level[l - 1].begin());
                edge.push_back({u + 1, v + 1});
                nhb[u]++;
                nhb[v]++;
                level[l].insert(v);
                if (nhb[u] == k)
                {
                    level[l - 1].erase(u);
                }
                if (nhb[v] == k)
                {
                    level[l].erase(v);
                }
            }
            else
            {
                ans = false;
                break;
            }
        }
    }
    if (!ans)
        cout << -1;
    else
    {
        cout << edge.size() << endl;
        for (auto e : edge)
            cout << e[0] << " " << e[1] << '\n';
    }

    return 0;
}