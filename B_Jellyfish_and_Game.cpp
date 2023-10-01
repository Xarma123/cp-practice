#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, m, k;
        cin >> n >> m >> k;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol b[m];
        for (lol i = 0; i < m; i++)
        {
            cin >> b[i];
        }

        sort(a, a + n);
        sort(b, b + m);
        if (n == 1)
        {
            if (k % 2)
                cout << max(a[n - 1], b[m - 1]) << '\n';
            else
                cout << min(a[0], b[0]) << '\n';
            continue;
        }
        else if (m == 1)
        {
            lol s = 0;
            lol mn = min(a[0], b[0]);
            lol mx = max(a[n - 1], b[0]);
            for (lol i = 0; i < n; i++)
            {
                s += a[i];
            }
            s += b[0];
            if (k % 2)
                cout << s - mn << '\n';
            else
                cout << s - mx << '\n';

            continue;
        }
        if (a[0] >= b[m - 1])
        {
            if (k % 2)
            {
                lol s = 0;
                for (lol i = 0; i < n; i++)
                {
                    s += a[i];
                }
                cout << s << '\n';
            }
            else
            {
                lol s = 0;
                for (lol i = 0; i < n - 1; i++)
                {
                    s += a[i];
                }
                s += b[0];
                cout << s << '\n';
            }
        }
        else
        {
            if (k % 2)
            {
                lol s = 0;
                for (lol i = 1; i < n; i++)
                {
                    s += a[i];
                }
                s += b[m - 1];
                cout << s << '\n';
            }
            else
            {
                lol s = 0;
                for (lol i = 1; i < n - 1; i++)
                {
                    s += a[i];
                }
                s += min(a[0], b[0]);
                s += min(a[n - 1], b[m - 1]);
                cout << s << '\n';
            }
        }
    }
}