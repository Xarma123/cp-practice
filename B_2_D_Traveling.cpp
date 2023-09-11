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
        lol n, k, a, b;
        cin >> n >> k >> a >> b;
        pair<lol, lol> p[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> p[i].first >> p[i].second;
        }
        a--;
        b--;
        k--;
        if (a <= k && b <= k)
        {
            cout << 0 << '\n';
        }
        else if (a > k && b > k)
        {
            lol ans = ((long long)abs(p[a].first - p[b].first) + (long long)abs(p[a].second - p[b].second));
            lol a1 = LONG_LONG_MAX;
            lol b1 = LONG_LONG_MAX;
            for (lol i = 0; i <= k; i++)
            {
                lol v = abs(p[i].first - p[b].first);
                v += abs(p[i].second - p[b].second);
                a1 = min(a1, v);
                v = abs(p[i].first - p[a].first);
                v += abs(p[i].second - p[a].second);
                b1 = min(b1, v);
            }
            if (a1 != LONG_LONG_MAX)
                ans = min(ans, a1 + b1);
            cout << ans << '\n';
        }
        else
        {
            if (a > b)
                swap(a, b);
            lol ans = LONG_LONG_MAX;
            for (lol i = 0; i <= k; i++)
            {
                lol v = abs(p[i].first - p[b].first);
                v += abs(p[i].second - p[b].second);
                ans = min(ans, v);
            }
            cout << ans << '\n';
        }
    }
}