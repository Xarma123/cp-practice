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
        lol area = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i].first >> a[i].second;
            area += a[i].first * 1ll * a[i].second;
        }
        sort(a, a + n);
        lol h = a[n - 1].first;
        lol w = area / h;
        lol i;
        for (i = n - 1; i > 0; i--)
        {
            if (a[i].first == h && a[i].second <= w)
            {
                w -= a[i].second;
            }
            else if (a[i].second == w && a[i].first <= h)
            {
                h -= a[i].first;
            }
            else
                break;
        }
        set<pair<lol, lol>> ans;
        if ((h == 0 && w == a[0].second) || (w == 0 && a[0].first == h))
        {
            h = a[n - 1].first;
            w = area / h;
            if (i < 0 && h * 1ll * w == area)
            {
                ans.insert({h, w});
            }
        }
        for (lol i = 0; i < n; i++)
        {
            swap(a[i].first, a[i].second);
        }
        sort(a, a + n);
        h = a[n - 1].first;
        w = area / h;
        for (i = n - 1; i > 0; i--)
        {
            if (a[i].first == h && a[i].second <= w)
            {
                w -= a[i].second;
            }
            else if (a[i].second == w && a[i].first <= h)
            {
                h -= a[i].first;
            }
            else
                break;
        }
        if ((h == 0 && w == a[0].second) || (w == 0 && a[0].first == h))
        {
            h = a[n - 1].first;
            w = area / h;
            if (i < 0 && h * 1ll * w == area)
            {
                ans.insert({w, h});
            }
        }
        cout << ans.size() << '\n';
        for (auto e : ans)
            cout << e.first << " " << e.second << '\n';
    }

    return 0;
}