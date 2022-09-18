#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    vector<pair<lol, pair<lol, lol>>> a;
    for (lol i = 0; i < n; i++)
    {
        lol s, p;
        cin >> s >> p;
        a.push_back({p, {(-s), i + 1}});
    }
    sort(a.rbegin(), a.rend());
    lol k;
    cin >> k;
    set<pair<lol, lol>> tb;
    for (lol i = 0; i < k; i++)
    {
        lol q;
        cin >> q;
        tb.insert({q, i + 1});
    }
    lol price = 0;
    vector<pair<lol, lol>> ans;
    for (lol i = 0; i < n; i++)
    {
        lol p = a[i].first;
        lol s = -a[i].second.first;
        lol id = a[i].second.second;
        auto it = tb.lower_bound({s, LONG_LONG_MIN});
        if (it == tb.end())
            continue;
        else
        {
            price += p;
            ans.push_back({id, (*it).second});
            tb.erase(it);
        }
    }
    cout << ans.size() << " " << price << endl;
    for (auto e : ans)
    {
        cout << e.first << " " << e.second << endl;
    }

    return 0;
}