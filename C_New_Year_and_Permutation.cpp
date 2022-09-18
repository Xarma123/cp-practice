#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n, m;
    cin >> n >> m;
    lol ans = 0;

    lol f[n + 1];
    f[0] = 1;
    for (lol i = 1; i <= n; i++)
    {
        f[i] = f[i - 1] * i % m;
    }

    for (lol r = 1; r <= n; r++)
    {
        lol c = ((n + 1 - r));

        c = c * 1ll * ((f[r] * 1ll * f[n - r + 1]) % m);

        ans = (ans + c);
        ans %= m;
    }
    cout << ans;

    return 0;
}