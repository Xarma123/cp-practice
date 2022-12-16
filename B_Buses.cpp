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
    lol mod = 1e9 + 7;
    map<lol, vector<lol>> mp;
    vector<pair<lol, lol>> f;
    for (lol i = 0; i < m; i++)
    {
        lol s, e;
        cin >> s >> e;
        mp[e].push_back(s);
    }
    f.push_back({0, 1});
    for (auto e : mp)
    {
        lol tot = 0;
        for (auto s : e.second)
        {
            lol w = f.back().second;
            lol st = -1, et = f.size();
            while (st != et - 1)
            {
                lol mid = (st + et) / 2;
                if (mid == -1)
                {
                    st = mid;
                }
                else if (mid == f.size())
                {
                    et = mid;
                }
                else if (f[mid].first < s)
                {
                    st = mid;
                }
                else
                    et = mid;
            }

            if (st > -1 && st < f.size())
            {
                w = (w % mod - f[st].second % mod + mod) % mod;
            }
            tot = (tot + w) % mod;
        }
        f.push_back({e.first, (tot + f.back().second) % mod});
    }

    if (f.back().first == n)
        cout << (f.back().second % mod - (f.size() >= 2 ? f[f.size() - 2].second : 0) % mod + mod) % mod;
    else
        cout << 0;

    return 0;
}