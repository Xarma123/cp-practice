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
        lol m, k, a1, ak;
        cin >> m >> k >> a1 >> ak;
        lol ans = LONG_LONG_MAX;
        for (lol i = 0; i * 1ll * k <= m; i++)
        {
            lol v = m - i * 1ll * k;
            v -= a1;
            v = max(v, 0ll);
            v += max(i - ak, 0ll);
            ans = min(ans, v);
        }
        cout << ans << '\n';
    }
}