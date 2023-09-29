#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    // a d  - e
    // b c d - f
    b = min(b, c);
    lol ans = 0;
    if (f >= e)
    {
        ans += min(b, d) * 1ll * f;
        d -= min(b, d);
        ans += min(a, d) * 1ll * e;
    }
    else
    {
        swap(a, b);
        swap(e, f);
        ans += min(b, d) * 1ll * f;
        d -= min(b, d);
        ans += min(a, d) * 1ll * e;
    }
    cout << ans;
}