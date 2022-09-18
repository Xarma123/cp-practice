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
    pair<lol, lol> a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a + n);
    pair<lol, lol> ans[n];
    for (lol i = 0; i < n; i++)
    {
        lol mn = LONG_LONG_MAX;
        if (i + 1 < n)
            mn = min(mn, a[i + 1].first - a[i].first);
        if (i - 1 >= 0)
            mn = min(mn, a[i].first - a[i - 1].first);
        lol mx = LONG_LONG_MIN;
        mx = max(mx, a[n - 1].first - a[i].first);
        mx = max(mx, a[i].first - a[0].first);
        ans[a[i].second] = {mn, mx};
    }
    for (lol i = 0; i < n; i++)
    {
        cout << ans[i].first << " " << ans[i].second << endl;
    }

    return 0;
}