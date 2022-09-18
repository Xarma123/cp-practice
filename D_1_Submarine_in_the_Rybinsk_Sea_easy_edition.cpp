#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lol pow[32];
    pow[0] = 1;
    for (lol i = 1; i < 32; i++)
    {
        pow[i] = (pow[i - 1] * 1ll * 10) % 998244353;
    }

    lol ans = 0;
    for (lol i = 0; i < n; i++)
    {
        lol p = 0;
        while (a[i] > 0)
        {
            lol e = a[i] % 10;
            a[i] /= 10;
            lol v = (e * 1ll * pow[2 * 1ll * p]) % 998244353;
            v = (v * 1ll * n * 1ll * 11) % 998244353;
            ans = (ans + v) % 998244353;
            p++;
        }
    }
    cout << ans;

    return 0;
}