#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, d;
    cin >> n >> d;
    pair<lol, lol> a[n];
    lol c[n + 1];
    c[0] = 0;
    for (lol i = 0; i < n; i++)
    {

        cin >> a[i].first >> a[i].second;
    }
    sort(a, a + n);
    for (lol i = 0; i < n; i++)
    {
        c[i + 1] = c[i] + a[i].second;
    }
    lol ans = LONG_LONG_MIN;
    for (lol i = 0; i < n; i++)
    {
        pair<lol, lol> q = {a[i].first + d, LONG_LONG_MIN};
        lol j = lower_bound(a, a + n, q) - a;
        ans = max(ans, c[j] - c[i]);
    }
    cout << ans;

    return 0;
}