#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol m, n;
    cin >> m >> n;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    lol i;
    for (i = n - 2; i >= 0; i--)
    {
        if ((a[i + 1] - a[i]) * 1ll * (n - i - 1) <= m)
        {
            m -= (a[i + 1] - a[i]) * 1ll * (n - i - 1);
        }
        else
        {
            break;
        }
    }
    lol ans = 0;
    if (i < 0)
    {
        if (m > 0)
        {
            lol x = m / n;
            lol r = m % n;
            for (lol j = 0; j < r; j++)
            {
                lol c = max(a[0] - x - 1, 0ll);
                ans += c * 1ll * c;
            }
            for (lol j = 0; j < n - r; j++)
            {
                lol c = max(a[0] - x, 0ll);
                ans += c * 1ll * c;
            }
        }
        else
        {
            for (lol i = 0; i < n; i++)
            {
                ans += a[0] * 1ll * a[0];
            }
        }
    }
    else
    {
        for (lol j = 0; j <= i; j++)
        {
            ans += a[j] * 1ll * a[j];
        }
        n = n - i - 1;
        if (m > 0)
        {
            lol x = m / n;
            lol r = m % n;
            for (lol j = 0; j < r; j++)
            {
                lol c = max(a[i + 1] - x - 1, 0ll);
                ans += c * 1ll * c;
            }
            for (lol j = 0; j < n - r; j++)
            {
                lol c = max(a[i + 1] - x, 0ll);
                ans += c * 1ll * c;
            }
        }
        else
        {
            for (lol i = 0; i < n; i++)
            {
                ans += a[i + 1] * 1ll * a[i + 1];
            }
        }
    }
    cout << ans;
}