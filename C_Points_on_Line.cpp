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
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lol ans = 0;
    for (lol i = 0; i < n; i++)
    {
        lol j = lower_bound(a + i, a + n, a[i] + d + 1) - a;
        j--;
        ans += (j - i) * 1ll * (j - i - 1) / 2;
    }
    cout << ans;

    return 0;
}