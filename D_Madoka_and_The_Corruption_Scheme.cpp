#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol mod = 1e9 + 7;
lol fact[100005];
lol invfact[100005];
lol inv(lol i)
{
    return i <= 1 ? i : mod - (long long)(mod / i) * inv(mod % i) % mod;
}
lol c(lol n, lol r)
{
    lol v = fact[n];
    v = (v * 1ll * invfact[r]) % mod;
    v = (v * 1ll * invfact[n - r]) % mod;

    return v;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, k;
    cin >> n >> k;
    for (lol i = 0; i < 100005; i++)
    {
        if (i == 0)
            fact[i] = 1;
        else
            fact[i] = (fact[i - 1] * 1ll * i) % mod;
    }
    for (lol i = 0; i < 100005; i++)
    {
        if (i)
            invfact[i] = (invfact[i - 1] * 1ll * inv(i)) % mod;
        else
            invfact[i] = 1;
    }
    // nc0 +nc1 .... + nck
    lol ans = 0;
    for (lol i = 0; i <= n && i <= k; i++)
    {

        ans = (ans + c(n, i)) % mod;
    }
    cout << ans;

    return 0;
}