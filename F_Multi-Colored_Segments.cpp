#include <bits/stdc++.h>
#define lol long long
using namespace std;
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
        set<pair<lol, pair<lol, lol>>> xl;
        set<pair<lol, pair<lol, lol>>> xr;
        set<lol> color;
        map<lol, vector<pair<lol, lol>>> seg;
        map<pair<lol, pair<lol, lol>>, lol> ind;
        for (lol i = 0; i < n; i++)
        {
            lol l, r, c;
            cin >> l >> r >> c;
            ind[{l, {r, c}}] = i;
            color.insert(c);
            xl.insert({l, {r, c}});
            xr.insert({r, {l, c}});
            seg[c].push_back({l, r});
        }
        lol a[n];
        for (auto q : color)
        {
            for (auto e : seg[q])
            {
                lol l = e.first, r = e.second;
                xl.erase({l, {r, q}});
                xr.erase({r, {l, q}});
            }
            for (auto e : seg[q])
            {
                lol ans = LONG_LONG_MAX;
                lol l = e.first, r = e.second;
                pair<lol, lol> w = {LONG_LONG_MIN, LONG_LONG_MIN};
                auto it = xl.lower_bound({l, w});

                if (it != xl.end())
                {

                    lol x = (*it).first;
                    if (x <= r)
                    {
                        ans = min(ans, 0ll);
                    }
                    else
                        ans = min(ans, x - r);
                } 
                if (it != xl.begin())
                {
                    it--;
                    if ((*it).second.first >= l)
                        ans = min(ans, 0ll);
                    else
                        ans = min(ans, l - (*it).second.first);
                }
                it = xl.lower_bound({r, w});

                if (it != xl.end())
                {

                    lol x = (*it).first;

                    ans = min(ans, x - r);
                }
                if (it != xl.begin())
                {
                    it--;
                    if ((*it).second.first >= r)
                        ans = min(ans, 0ll);
                    else
                        ans = min(ans, r - (*it).second.first);
                }

                a[ind[{l, {r, q}}]] = ans;
            }
            for (auto e : seg[q])
            {
                lol l = e.first, r = e.second;
                xl.insert({l, {r, q}});
                xr.insert({r, {l, q}});
            }
        }
        for (lol i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    return 0;
}