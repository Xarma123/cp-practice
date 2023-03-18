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
        pair<lol, lol> a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i].first >> a[i].second;
        }
        sort(a, a + n);
        lol suf[n];
        for (lol i = n - 1; i >= 0; i--)
        {
            if (i == n - 1)
            {
                suf[i] = a[i].second;
            }
            else
            {
                suf[i] = max(suf[i + 1], a[i].second);
            }
        }
        set<lol> x;
        lol ans = LONG_LONG_MAX;
        for (lol i = 0; i < n; i++)
        {
            if (i < n - 1)
            {
                ans = min(ans, (long long)abs(a[i].first - suf[i + 1]));
                auto it = x.lower_bound(a[i].first);
                if (it != x.end())
                {
                    if ((*it) > suf[i + 1])
                        ans = min(ans, (long long)abs(a[i].first - (*it)));
                }
                if (it != x.begin())
                {
                    it--;
                    if ((*it) > suf[i + 1])
                        ans = min(ans, (long long)abs(a[i].first - (*it)));
                }
            }
            else
            {
                auto it = x.lower_bound(a[i].first);
                if (it != x.end())
                {
                    ans = min(ans, (long long)abs(a[i].first - (*it)));
                }
                if (it != x.begin())
                {
                    it--;
                    ans = min(ans, (long long)abs(a[i].first - (*it)));
                }
            }
            x.insert(a[i].second);
        }
        cout << ans << '\n';
    }

    return 0;
}