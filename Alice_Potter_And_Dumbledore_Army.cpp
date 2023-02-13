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
    map<lol, lol> mp;
    vector<pair<lol, lol>> v;
    while (m--)
    {
        lol p, t;
        cin >> p >> t;
        v.push_back({p, t});
    }
    set<pair<lol, lol>> x;
    map<lol, lol> last, mpp;
    vector<lol> ans;
    for (lol i = 0; i < v.size(); i++)
    {
        if (i == 0)
        {
            last[v[i].first] = v[i].second;
            mpp[v[i].first] += v[i].second;
            x.insert({-v[i].second, v[i].first});
            ans.push_back(v[i].second);
        }
        else
        {
            lol ol = -(*x.begin()).first;
            lol p = (*x.begin()).second;
            x.erase(x.begin());
            mpp[p] -= last[p];
            x.insert({-mpp[p], p});
            if (mpp.count(v[i].first))
                x.erase({-mpp[v[i].first], v[i].first});
            mpp[v[i].first] += v[i].second;
            x.insert({-mpp[v[i].first], v[i].first});
            lol ns = -(*x.begin()).first;
            x.erase({-mpp[p], p});
            mpp[p] += last[p];
            x.insert({-mpp[p], p});
            last[v[i].first] = v[i].second;
            ans.push_back(-(*x.begin()).first + ans.back() + min(ns - ol, 0ll));
        }
        cout << ans.back() << '\n';
    }

    return 0;
}