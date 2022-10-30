#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m, k, x, y;
    cin >> n >> m >> k >> x >> y;
    if (n == 1)
    {
        cout << k / m + (k % m > 0) << " " << k / m << " ";
        if (k % m >= y)
        {
            cout << k / m + 1;
        }
        else
            cout << k / m;
    }
    else if (k <= n * m)
    {
        cout << 1 << " ";
        if (n * m == k)
            cout << 1 << " ";
        else
        {
            cout << 0 << " ";
        }
        if ((x - 1) * m + y <= k)
            cout << 1;
        else
            cout << 0;
    }
    else if (n == 2)
    {
        k -= n * m;
        lol c = k / m;
        lol top = 1 + c / 2 + (c % 2);
        lol bot = 1 + c / 2;
        lol b1 = bot, b2 = bot;
        lol t1 = top, t2 = top;

        if (k % m)
        {
            if (c % 2)
            {
                if (x == 2)
                {
                    if (y <= k % m)
                    {
                        bot++;
                    }
                }
                b1++;
            }
            else
            {
                if (x == 1)
                {
                    if (y <= k % m)
                    {
                        top++;
                    }
                }
                t1++;
            }
        }
        cout << max(t1, max(t2, max(b1, b2))) << " ";
        cout << min(t1, min(t2, min(b1, b2))) << " ";
        if (x == 1)
            cout << top;
        else
            cout << bot;
    }
    else
    {
        k -= n * m;
        lol c = k / (m * (n - 1));
        lol top = 1 + c / 2 + (c % 2);
        lol bot = 1 + c / 2;
        lol mid = 1 + c;
        lol a[n][m];
        lol mn = min(top, min(bot, mid));
        lol mx = max(top, max(bot, mid));
        for (lol i = 0; i < m; i++)
        {
            a[0][i] = top;
        }
        for (lol i = 0; i < m; i++)
        {
            a[n - 1][i] = bot;
        }
        for (lol i = 1; i < n - 1; i++)
        {
            for (lol j = 0; j < m; j++)
            {
                a[i][j] = mid;
            }
        }
        lol v = k % (m * (n - 1));

        if (c % 2)
        {
            for (lol i = 1; i < n && v; i++)
            {
                for (lol j = 0; j < m && v; j++)
                {
                    a[i][j]++;
                    mx = max(mx, a[i][j]);
                    mn = min(mn, a[i][j]);
                    v--;
                }
            }
        }
        else
        {
            for (lol i = n - 2; i >= 0 && v; i--)
            {
                for (lol j = 0; j < m && v; j++)
                {
                    a[i][j]++;
                    mx = max(mx, a[i][j]);
                    mn = min(mn, a[i][j]);
                    v--;
                }
            }
        }
        cout << mx << " " << mn << " " << a[x - 1][y - 1];
    }

    return 0;
}