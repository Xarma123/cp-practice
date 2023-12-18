#include <bits/stdc++.h>
using namespace std;
#define lol long long
const lol mx = (1ll << 20);
lol dp[mx];
lol dp2[20][mx];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, q;
    cin >> n >> q;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    memset(dp, 0ll, sizeof(dp));
    for (lol i = 0; i < n; i++)
    {
        dp[a[i]]++;
    }
    for (lol i = 0; i < 20; i++)
    {
        for (lol j = 0; j < mx; j++)
        {
            if ((j & (1ll << i)))
            {
                dp[j] += dp[(j ^ (1ll << i))];
            }
        }
    }

    memset(dp2, 0, sizeof(dp2));
    for (lol i = 0; i < 20; i++)
    {
        for (lol j = 0; j < n; j++)
        {
            dp2[i][a[j]] += (a[j] % (1ll << i));
        }
    }
    for (lol i = 0; i < 20; i++)
    {
        for (lol j = 0; j < 20; j++)
        {
            for (lol k = 0; k < mx; k++)
            {
                if ((k & (1ll << j)))
                {
                    dp2[i][k] += dp2[i][(k ^ (1ll << j))];
                    dp2[i][k] %= (1ll << i);
                }
            }
        }
    }

    while (q--)
    {
        lol k;
        cin >> k;
        lol ans = 0;
        for (lol i = 21; i >= 0; i--)
        {
            lol v = (ans | (1ll << i));

            lol x = (1ll << i) * 1ll * (n - dp[v]);
            x -= dp2[i][v ^ (1ll << i)] - dp2[i][v];
            if (x <= k)
            {
                x -= k;
                ans |= (1ll << i);
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
