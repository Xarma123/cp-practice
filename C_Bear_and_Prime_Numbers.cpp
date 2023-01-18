#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol lpf[10000005];
map<lol, lol> mp;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (lol i = 2; i < 10000005; i++)
    {
        if (lpf[i] == 0)
        {
            lpf[i] = i;
            for (lol j = i * 1ll * i; j < 10000005; j += i)
            {
                lpf[j] = i;
            }
        }
    }
    lol n;
    cin >> n;
    for (lol i = 0; i < n; i++)
    {
        lol q;
        cin >> q;
        set<lol> x;
        while (q > 1)
        {
            x.insert(lpf[q]);
            q /= lpf[q];
        }
        for (auto e : x)
            mp[e]++;
    }
    vector<pair<lol, lol>> v;
    for (auto e : mp)
    {
        if (v.size())
            v.push_back({e.first, e.second + v.back().second});
        else
            v.push_back(e);
    }
    lol m;
    cin >> m;
    while (m--)
    {
        lol l, r;
        cin >> l >> r;
        lol st = -1, e = v.size();
        while (st != e - 1)
        {
            lol md = (st + e) / 2;
            if (md == -1)
                st = md;
            else if (md == v.size())
                e = md;
            else if (v[md].first >= l)
            {
                e = md;
            }
            else
                st = md;
        }
        lol ans = 0;
        if (e - 1 >= 0)
        {
            ans -= v[e - 1].second;
        }
        st = -1, e = v.size();
        while (st != e - 1)
        {
            lol md = (st + e) / 2;
            if (md == -1)
                st = md;
            else if (md == v.size())
                e = md;
            else if (v[md].first <= r)
            {
                st = md;
            }
            else
                e = md;
        }
        if (st != -1)
            ans += v[st].second;
        cout << ans << '\n';
    }

    return 0;
}