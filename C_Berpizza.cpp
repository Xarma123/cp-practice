#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol q;
    cin >> q;
    multiset<pair<lol, lol>> x;
    multiset<pair<lol, lol>> y;
    vector<lol> ans;
    lol c = 1;

    lol serve = 1;
    while (q--)
    {
        lol n;
        cin >> n;
        if (n == 1)
        {
            lol t;
            cin >> t;
            x.insert(make_pair(t, c));
            y.insert(make_pair(c, t));
            c++;
        }
        else if (n == 2)
        {
            auto i = y.begin();
            ans.push_back((*i).first);
            pair<lol, lol> f = make_pair((*i).second, (*i).first);
            y.erase(i);
            i = x.find(f);
            x.erase(i);
        }
        else
        {
            auto s = (*x.rbegin());
            lol g = s.first;
            auto d = x.lower_bound(make_pair(g, INT_MIN));
            ans.push_back((*d).second);
            pair<lol, lol> f = make_pair((*d).second, (*d).first);
            x.erase(d);
            d = y.find(f);
            y.erase(d);
        }
    }
    for (lol i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}