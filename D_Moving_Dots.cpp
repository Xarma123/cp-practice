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
    lol a[n];
    lol p[n + 1];
    p[0] = 1ll;
    lol m = 1e9 + 7;
    for (lol i = 1; i <= n; i++)
        p[i] = (p[i - 1] * 2ll) % m;

    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lol ans = 0;
    for (lol i = 0; i < n; i++)
    {
        for (lol j = i + 1; j < n; j++)
        {
            lol x = a[j] - a[i];
            lol l = lower_bound(a, a + n, a[i] - x) - a;
            lol r = n - (lower_bound(a, a + n, a[j] + x) - a);
            ans += p[r + l];
            ans %= m;
        }
    }
    cout << ans;

    return 0;
}