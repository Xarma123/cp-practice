#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n;
    cin >> n;
    pair<lol, lol> a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    lol m;
    cin >> m;
    pair<lol, lol> b[m];
    for (lol i = 0; i < m; i++)
    {
        cin >> b[i].first >> b[i].second;
    }
    sort(a, a + n);
    sort(b, b + m);
    lol ans = LONG_LONG_MIN;
    for (lol i = 0; i < n; i++)
    {
        ans = max(b[m - 1].first - a[i].second, ans);
    }
    for (lol i = 0; i < m; i++)
    {
        ans = max(a[n - 1].first - b[i].second, ans);
    }
    if (ans < 0)
        cout << 0;
    else
        cout << ans;

    return 0;
}