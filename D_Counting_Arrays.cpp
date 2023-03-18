#include <bits/stdc++.h>
#define lol long long
using namespace std;
bool p(lol a)
{
    for (lol i = 2; i * 1ll * i <= a; i++)
    {
        if (a % i == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    lol mod = 998244353;
    lol tot = 1;
    lol wow = 0;
    for (lol i = 1; i <= n; i++)
    {
        tot = (tot * 1ll * (m % mod)) % mod;
        wow += tot;
        wow %= mod;
    }
    lol c = 1;
    lol v = 1;
    for (lol i = 1; i <= n; i++)
    {
        if (p(i))
            v = (v * 1ll * i);
        c = (c * 1ll * ((m / v) % mod)) % mod;
        wow = ((wow - c + mod) % mod + mod) % mod;
    }

    cout << wow;
    return 0;
}