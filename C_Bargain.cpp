#include <bits/stdc++.h>
using namespace std;
#define lol long long
lol modInverse(lol A, lol M)
{
    lol m0 = M;
    lol y = 0, x = 1;
    if (M == 1)
        return 0;
    while (A > 1)
    {
        lol q = A / M;
        lol t = M;
        M = A % M, A = t;
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
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    lol n = s.size();
    lol mod = 1e9 + 7;
    lol d = modInverse(81, mod);
    lol pw[n + 1];
    for (lol i = 0; i <= n; i++)
    {
        if (i == 0)
            pw[i] = 1;
        else
            pw[i] = (10ll * pw[i - 1]) % mod;
    }
    lol ans = 0;
    for (lol i = 0; i < n; i++)
    {
        lol c = s[i] - '0';
        ans += (((((pw[n - i - 1] * 1ll * (9ll * (n - i - 1) - 1) + 1) % mod) * 1ll * d) % mod) * 1ll * c) % mod;
        ans %= mod;
        ans += (((pw[n - 1 - i] * 1ll * c) % mod) * 1ll * ((i * 1ll * (i + 1)) / 2ll)) % mod;
        ans %= mod;
    }
    cout << ans;
}