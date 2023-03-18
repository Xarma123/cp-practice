#include <bits/stdc++.h>
#define lol long long
using namespace std;
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
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[n];
        lol m = 998244353;
        lol z = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] == 0)
                z++;
        }
        lol dp[z + 1];
        for (lol i = z; i >= 0; i--)
        {
            if (i == z)
            {
                dp[i] = 0;
            }
            else
            {
                dp[i] = dp[i + 1];
                dp[i] = (dp[i] + (((n * 1ll * (n - 1) / 2ll) % m) * 1ll * modInverse(((z - i) * 1ll * (z - i)), m)) % m) % m;
            }
        
        }
      
        lol q = 0;
        for (lol i = 0; i < z; i++)
        {
            if (a[i] == 0)
                q++;
        }
        cout << (dp[q] % m) << '\n';
    }

    return 0;
}