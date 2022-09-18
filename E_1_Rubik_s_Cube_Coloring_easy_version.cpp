#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol m = 1e9 + 7;
lol p(lol a, lol b, lol m)
{
    lol r = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
            r = (r * 1ll * a) % m;
        a = (a * 1ll * a) % m;
        b /= 2;
    }
    return r;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol k;
    cin >> k;
    lol n = (1ll << k) - 2;
    lol ans = p(4ll, n, m);
    ans = (ans * 1ll * 6) % m;
    cout << ans << endl;

    return 0;
}