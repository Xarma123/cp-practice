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
        lol n, x;
        cin >> n >> x;
        vector<pair<lol, lol>> v;
        while (n--)
        {
            lol d, h;
            cin >> d >> h;
            v.push_back({d, h});
        }
        sort(v.begin(), v.end());
        lol mx = v.back().first;
        for (lol i = 0; i < v.size(); i++)
        {
            v[i].first = v[i].second - v[i].first;
        }
        sort(v.begin(), v.end());
        lol dm = v[0].first;
        if (mx >= x)
        {
            cout << 1 << '\n';
        }
        else
        {
            if (dm >= 0)
                cout << -1 << '\n';
            else
            {

                lol ans = ceill((x - mx) / (long double)(-dm));
                x += ans * 1ll * dm;
                if (x >= 0)
                    ans++;
                cout << ans << '\n';
            }
        }
    }
}