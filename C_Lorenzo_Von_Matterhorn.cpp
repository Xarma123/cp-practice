#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol q;
    cin >> q;
    map<pair<lol, lol>, lol> mp;
    while (q--)
    {
        lol t;
        cin >> t;
        if (t == 1)
        {
            lol u, v, w;
            cin >> u >> v >> w;
            lol lu = log2l(u);
            lol lv = log2l(v);
            if (lu < lv)
            {
                swap(lu, lv);
                swap(u, v);
            }
            while (lu != lv)
            {
                mp[{u, u / 2}] += w;
                u = u / 2;
                lu--;
            }
            while (u != v)
            {
                mp[{u, u / 2}] += w;
                u = u / 2;
                mp[{v, v / 2}] += w;
                v = v / 2;
            }
        }
        else
        {
             lol ans = 0;
            lol u, v;
            cin >> u >> v;
            lol lu = log2l(u);
            lol lv = log2l(v);
            if (lu < lv)
            {
                swap(lu, lv);
                swap(u, v);
            }
            while (lu != lv)
            {
                ans += mp[{u, u / 2}];
                u = u / 2;
                lu--;
            }
            while (u != v)
            {
                ans += mp[{u, u / 2}];
                u = u / 2;
                ans += mp[{v, v / 2}];
                v = v / 2;
            }
            cout << ans << endl;
        }
    }

    return 0;
}