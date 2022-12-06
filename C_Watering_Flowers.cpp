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
    lol c1, c11, c2, c22;
    cin >> c1 >> c11 >> c2 >> c22;

    vector<pair<lol, lol>> v;
    vector<lol> r;
    for (lol i = 0; i < n; i++)
    {
        lol x, y;
        cin >> x >> y;
        lol r1 = (x - c1) * 1ll * (x - c1) + (y - c11) * 1ll * (y - c11);
        v.push_back({x, y});
        r.push_back(r1);
    }
    r.push_back(0);
    lol ans = LONG_LONG_MAX;
    for (auto r1 : r)
    {
        lol r2 = 0;
        for (lol i = 0; i < n; i++)
        {
            lol x = v[i].first;
            lol y = v[i].second;
            if (r1 >= (x - c1) * 1ll * (x - c1) + (y - c11) * 1ll * (y - c11))
            {
                continue;
            }
            r2 = max(r2, (x - c2) * 1ll * (x - c2) + (y - c22) * 1ll * (y - c22));
        }
        ans = min(ans, r1 + r2);
    }
    cout << ans;

    return 0;
}