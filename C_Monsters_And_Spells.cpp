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
        lol k[n], h[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> k[i];
        }
        for (lol i = 0; i < n; i++)
        {
            cin >> h[i];
        }
        vector<pair<lol, lol>> v;
        for (lol i = 0; i < n; i++)
        {
            lol r = k[i];
            lol l = k[i] - h[i] + 1;
            while (v.size() > 0 && v.back().second >= l)
            {
                l = min(l, v.back().first);
                v.pop_back();
            }
            v.push_back({l, r});
        }
        lol ans = 0;
        for (auto e : v)
        {
            ans += (e.second - e.first + 1) * 1ll * (e.second - e.first + 2) / 2;
        }
        cout << ans << '\n';
    }

    return 0;
}