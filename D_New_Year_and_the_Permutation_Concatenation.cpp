#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol modInverse(lol a, lol m)
{
    lol m0 = m;
    lol y = 0, x = 1;

    if (m == 1)
        return 0;

    while (a > 1)
    {

        lol q = a / m;
        lol t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x = (x % m0 + m0) % m0;

    return x;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol m = 998244353;
    lol f[n + 1];
    f[0] = 1, f[1] = 1;
    for (lol i = 2; i <= n; i++)
    {
        f[i] = (f[i - 1] * 1ll * i) % m;
    }

    lol v1 = 0;
    for (lol i = 1; i < n; i++)
    {
        v1 = (v1 + (f[n] * 1ll * modInverse(f[i], m)) % m) % m;
    }
    f[n] = (f[n] * 1ll * n) % m;

    f[n] = (f[n] - v1 + m) % m;
    cout << f[n] << endl;

    return 0;
}