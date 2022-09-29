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
            cin >> a[i].first;
        }

        for (lol i = 0; i < n; i++)
        {
            cin >> a[i].second;
        }
        sort(a, a + n);
        lol cleft[n + 1];
        cleft[0] = INT_MAX;
        for (lol i = 0; i < n; i++)
        {
            cleft[i + 1] = min(a[i].first - a[i].second, cleft[i]);
        }
        lol cright[n + 1];
        cright[n] = INT_MIN;
        for (lol i = n - 1; i >= 0; i--)
        {
            cright[i] = max(a[i].first + a[i].second, cright[i + 1]);
        }
        long double tmin = INT_MAX;
        long double ans;
        for (lol i = 0; i < n; i++)
        {
            lol tm = a[i].second;
            tm = max(tm, a[i].first - cleft[i]);
            tm = max(tm, cright[i + 1] - a[i].first);
            if (tm < tmin)
            {
                ans = a[i].first;
                tmin = tm;
            }
        }
        long double mid = (a[0].first + a[n - 1].first) / (long double)2;
        for (lol i = 0; i < n - 1; i++)
        {
            if (a[i].first < mid && a[i + 1].first > mid)
            {
                long double tm = INT_MIN;
                tm = max(tm, mid - cleft[i + 1]);
                tm = max(tm, cright[i + 1] - mid);
                if (tm < tmin)
                {
                    ans = mid;
                    tmin = tm;
                }
            }
            long double nmid = (a[i].first + a[i + 1].first) / (long double)2;
            long double tm = INT_MIN;
            tm = max(tm, nmid - cleft[i + 1]);
            tm = max(tm, cright[i + 1] - nmid);
            if (tm < tmin)
            {
                ans = nmid;
                tmin = tm;
            }
        }
        cout << fixed << setprecision(7) << ans << endl;
    }

    return 0;
}