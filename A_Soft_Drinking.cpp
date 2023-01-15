#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
    lol ans = LONG_LONG_MAX;
    ans = min(ans, c * 1ll * d);
    ans = min(ans, k * 1ll * l / nl);
    ans = min(ans, p / np);
    cout << ans / n;

    return 0;
}