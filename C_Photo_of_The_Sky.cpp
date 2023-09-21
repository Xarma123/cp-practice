#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    n = n;
    lol a[2ll * n];
    for (lol i = 0; i < 2ll * n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + 2ll * n);
    lol ans = (a[2ll * n - 1] - a[n]) * 1ll * (a[n - 1] - a[0]);
    for (lol i = 1; i < n; i++)
    {
        ans = min(ans, (a[i + n - 1] - a[i]) * 1ll * (a[2ll * n - 1] - a[0]));
    }
    lol j = n - 1;
    for (lol i = n; i < 2 * n - 1; i++)
    {
        ans = min(ans,(a[i] - a[0]) * 1ll * (a[2ll * n - 1] - a[j]));
    }

    cout << ans;
}