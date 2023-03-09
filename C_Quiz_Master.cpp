#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, m;
        cin >> n >> m;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        lol r = 0;
        lol mp[m + 1];
        memset(mp, 0, sizeof(mp));
        lol c = 0;
        lol ans = LONG_LONG_MAX;
        for (lol i = 0; i < n; i++)
        {
            if (i > 0)
            {
                for (lol j = 1; j * 1ll * j <= a[i - 1]; j++)
                {
                    if (a[i - 1] % j == 0)
                    {
                        lol d = j;
                        if (d >= 1 && d <= m)
                        {
                            mp[d]--;
                            if (mp[d] == 0)
                                c--;
                        }
                        if (a[i - 1] / j != j)
                        {
                            d = a[i - 1] / d;
                            if (d >= 1 && d <= m)
                            {
                                mp[d]--;
                                if (mp[d] == 0)
                                    c--;
                            }
                        }
                    }
                }
            }
            for (; r < n && c < m; r++)
            {
                for (lol k = 1; k * 1ll * k <= a[r]; k++)
                {
                    if (a[r] % k == 0)
                    {
                        lol d = k;
                        if (d >= 1 && d <= m)
                        {
                            if (++mp[d] == 1)
                                c++;
                        }
                        if (a[r] / k != k)
                        {
                            d = a[r] / d;
                            if (d >= 1 && d <= m)
                                if (++mp[d] == 1)
                                    c++;
                        }
                    }
                }
            }
            if (c == m)
            {
                ans = min(ans, a[r - 1] - a[i]);
            }
        }
        if (ans == LONG_LONG_MAX)
            ans = -1;
        cout << ans << '\n';
    }

    return 0;
}