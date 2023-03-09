#include <bits/stdc++.h>
#define lol long long
using namespace std;
bool is(lol a)
{
    lol q = ceill(sqrt(a));
    return (q * 1ll * q) == a;
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
        for (lol i = 0; i < n; i++)
            cin >> a[i];
        lol ans = 1;
        for (lol k = 0; k < n; k++)
        {
            for (lol j = k + 1; j < n; j++)
            {
                lol d = a[j] - a[k];

                for (lol i = 1; i * 1ll * i <= d; i++)
                {
                    if (d % i == 0)
                    { // x + y = i
                        // y - x = d/i
                        // y = (d/i +i)/2
                        // x = i - ((d/i +i)/2)
                        if (((d / i) + i) % 2 == 0)
                        {
                            lol y = ((d / i) + i) / 2;
                            lol x = i - y;
                            if (x >= 0)
                            {
                                lol k_ = x * 1ll * x - a[k];
                                if (k_ >= 0 && k_ == y * 1ll * y - a[j])
                                {
                                    lol v = 0;
                                    for (lol q = 0; q < n; q++)
                                    {
                                        if (is(a[q] + k_))
                                            v++;
                                    }
                                    ans = max(ans, v);
                                }
                            }
                            x = d / i - y;
                            if (x >= 0)
                            {
                                lol k_ = x * 1ll * x - a[k];
                                if (k_ >= 0 && k_ == y * 1ll * y - a[j])
                                {
                                    lol v = 0;
                                    for (lol q = 0; q < n; q++)
                                    {
                                        if (is(a[q] + k_))
                                            v++;
                                    }
                                    ans = max(ans, v);
                                }
                            }
                        }
                    }
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}