#include <bits/stdc++.h>
#define lol long long
using namespace std;
lol f[1000005];
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
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            f[a[i]]++;
        }
        lol ans = 0;

        for (lol i = 0; i < n; i++)
        {
            ans += (f[a[i]] - 1) * 1ll * (f[a[i]] - 2);
            for (lol j = 2; j * 1ll * j <= a[i]; j++)
            {
                if (a[i] % j == 0)
                {
                    lol d = a[i] / j;
                    d = a[i] * 1ll * d;
                    if (d < 1000005)
                        ans += f[j] * 1ll * f[d];
                    lol j2 = a[i] / j;
                    if (j2 != j)
                    {
                        d = a[i] / j2;
                        d = a[i] * 1ll * d;
                        if (d < 1000005)
                            ans += f[j2] * 1ll * f[d];
                    }
                }
            }
            if (a[i] > 1)
                if (a[i] * 1ll * a[i] < 1000005)
                    ans += f[1] * 1ll * f[(a[i] * 1ll * a[i])];
        }
        for (lol i = 0; i < n; i++)
        {

            f[a[i]]--;
        }
        cout << ans << '\n';
    }
    return 0;
}