#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    lol md = 1e9 + 7;
    lol a = 2;
    lol r = 1;
    while (m > 0)
    {
        if (m % 2)
            r = (r * 1ll * a) % md;
        a = (a * 1ll * a) % md;
        m /= 2;
    }
    r = ((r - 1) % md + md) % md;
    lol ans = 1;
    while (n > 0)
    {
        if (n % 2)
            ans = (ans * 1ll * r) % md;
        r = (r * 1ll * r) % md;
        n /= 2;
    }
    cout << ans;
}