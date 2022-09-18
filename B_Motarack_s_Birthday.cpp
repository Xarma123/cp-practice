#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
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
        }
        lol mn = LONG_LONG_MAX;
        lol mx = LONG_LONG_MIN;
        for (lol i = 0; i < n; i++)
        {
            if (a[i] == -1)
            {
                if (i - 1 >= 0)
                {
                    if (a[i - 1] != -1)
                    {
                        mn = min(mn, a[i - 1]);
                        mx = max(mx, a[i - 1]);
                    }
                }
                if (i + 1 < n)
                {
                    if (a[i + 1] != -1)
                    {
                        mn = min(mn, a[i + 1]);
                        mx = max(mx, a[i + 1]);
                    }
                }
            }
        }
        lol ans = LONG_LONG_MIN;

        for (lol i = 0; i < n - 1; i++)
        {
            if (a[i] == -1)
                a[i] = (mn + mx) / 2;
            if (a[i + 1] == -1)
                a[i + 1] = (mn + mx) / 2;

            ans = max(ans, abs(a[i] - a[i + 1]));
        }

        cout << ans << " " << (mn + mx) / 2 << endl;
    }

    return 0;
}