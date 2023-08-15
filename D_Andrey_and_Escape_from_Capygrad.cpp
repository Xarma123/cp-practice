#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        vector<pair<lol, lol>> v;
        while (n--)
        {
            lol l, r, a, b;
            cin >> l >> r >> a >> b;
            v.push_back({b, l});
        }
        lol q;
        cin >> q;
        vector<lol> x;
        for (lol i = 0; i < q; i++)
        {
            lol a;
            cin >> a;
            x.push_back(a);
        }
        vector<pair<lol, lol>> a;
        for (auto e : x)
        {
            a.push_back({e, e});
        }
        for (lol i = 0; i < v.size(); i++)
        {
            a.push_back(v[i]);
            a.push_back({v[i].second, v[i].first});
        }
        map<lol, lol> d;
        sort(a.begin(), a.end());
        multiset<lol> as;
        for (lol i = a.size() - 1; i >= 0; i--)
        {
            d[a[i].first] = max(d[a[i].first], a[i].first);
            if (as.size())
            {
                d[a[i].first] = max(d[a[i].first], (*as.rbegin()));
            }
            if (a[i].second < a[i].first)
            {
                as.insert(d[a[i].first]);
            }
            if (a[i].second > a[i].first)
            {
                as.erase(as.find(d[a[i].second]));
            }
        }
        for (auto e : x)
            cout << d[e] << " ";
        cout << '\n';
    }
}