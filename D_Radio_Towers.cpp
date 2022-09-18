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
        x += m0;

    return x;
}
int main()
{
    lol n;
    cin >> n;
    lol dp[n];
    dp[0] = 1;
    for (lol i = 1; i < n; i++)
    {
        if (i == 1)
            dp[i] = 1;
        else
            dp[i] = (dp[i - 1] + dp[i - 2]) % 998244353;
    }
    lol v = modInverse(2, 998244353);
    lol V = v;
    for (lol i = 1; i < n; i++)
    {
        V = (V * 1ll * v) % 998244353;
    }
    cout << dp[n - 1] * V % 998244353;

    return 0;
}