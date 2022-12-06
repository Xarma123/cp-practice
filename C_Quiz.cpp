#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m, k;
    lol mod = 1e9 + 9;
    cin >> n >> m >> k;
    if ((n / k) * 1ll * (k - 1) + n % k >= m)
        cout << m;
    else
    {
        m -= (n / k) * 1ll * (k - 1) + n % k;
        lol ans = ((n / k) * 1ll * (k - 1) + n % k) % mod;
        lol a = 2;
        lol v = 1;
        lol M = m;
        m++;
        while (m)
        {
            if (m % 2)
                v = (v * 1ll * a) % mod;
            m /= 2;
            a = (a * 1ll * a) % mod;
        }
        v = (v + mod - 2) % mod;
        v = (v * 1ll * k) % mod;
        v = (v + M) % mod;
        v = (v + mod - (M * 1ll * k) % mod) % mod;
        ans = (ans + v) % mod;
        cout << ans;
    }

    return 0;
}