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

        set<pair<lol, lol>> x;
        for (lol i = 0; i < n; i++)
        {
            lol v;
            cin >> v;
            x.insert({v, i});
        }
        vector<pair<lol, lol>> ans;
        while ((*x.begin()).first != (*x.rbegin()).first)
        {
            pair<lol, lol> a = (*x.begin());
            x.erase(a);
            pair<lol, lol> b = (*x.rbegin());
            x.erase(b);
            if (a.first == 1)
            {
                ans.clear();
                ans.push_back({-1, -1});
                break;
            }
            ans.push_back({b.second + 1, a.second + 1});
            b.first = (b.first + a.first - 1) / a.first;
            x.insert(a);
            x.insert(b);
        }
        if (ans.size() && ans[0].first == -1)
            cout << -1 << '\n';
        else
        {
            cout << ans.size() << '\n';
            for (auto e : ans)
            {
                cout << e.first << " " << e.second << '\n';
            }
        }
    }
}