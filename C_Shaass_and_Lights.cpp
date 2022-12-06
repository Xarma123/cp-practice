#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol mod = 1e9 + 7;
lol modInverse(lol A, lol M)
{
    lol m0 = M;
    lol y = 0, x = 1;

    if (M == 1)
        return 0;

    while (A > 1)
    {
        // q is quotient
        lol q = A / M;
        lol t = M;

        // m is remainder now, process same as
        // Euclid's algo
        M = A % M, A = t;
        t = y;

        // Update y and x
        y = x - q * y;
        x = t;
    }

    // Make x positive
    if (x < 0)
        x += m0;

    return x;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    string s = "";
    while (n--)
    {
        s.push_back('0');
    }
    for (lol i = 0; i < m; i++)
    {
        lol q;
        cin >> q;
        s[q - 1] = '1';
    }
    n = s.size();
    lol dp[n + 1];
    dp[0] = 1;
    dp[1] = 1;
    for (lol i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] * 1ll * 2;
        dp[i] %= mod;
    }
    lol fact[n + 1];
    fact[0] = 1;
    for (lol i = 1; i <= n; i++)
    {
        fact[i] = fact[i - 1] * 1ll * i;
        fact[i] %= mod;
    }
    lol invfact[n + 1];
    invfact[1] = modInverse(1, mod);
    for (lol i = 2; i <= n; i++)
    {
        invfact[i] = (invfact[i - 1] * 1ll * modInverse(i, mod)) % mod;
    }
    lol ans = 1;
    lol tot = 0;
    bool f = false;
    for (lol i = 0; i < n; i++)
    {
        lol j = i + 1;
        while (j < n && s[j] == s[i])
            j++;

        if (s[i] == '0')
        {
            tot += j - i;
            if (i != 0 && j != n)
            {
                ans = ans * 1ll * dp[j - i];
                ans %= mod;
            }
            ans = ans * 1ll * invfact[j - i];
            ans %= mod;
        }
       

        i = j - 1;
    }
    ans = ans * 1ll * fact[tot];
    ans %= mod;
    cout << ans;

    return 0;
}