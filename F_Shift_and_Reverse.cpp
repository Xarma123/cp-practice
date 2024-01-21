#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[2ll * n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (lol i = n; i < 2ll * n; i++)
        {
            a[i] = a[i - n];
        }
        lol ans = LONG_LONG_MAX;
        for (lol i = 0; i < n; i++)
        {
            lol j = i + 1;
            while (j < 2ll * n && a[j] >= a[j - 1])
            {
                j++;
            }
            if (j - i >= n)
            {
                ans = min(ans, ((n - i) % n));
                ans = min(ans, 2 + ((n - ((n - i) % n)) % n));
            }
            i = j - 1;
        }
        for (lol i = 0; i < n; i++)
        {
            lol j = i + 1;
            while (j < 2ll * n && a[j] <= a[j - 1])
            {
                j++;
            }
            if (j - i >= n)
            {
                ans = min(ans, ((n - i) % n) + 1);
                ans = min(ans, 1 + ((n - ((n - i) % n)) % n));
            }
            i = j - 1;
        }
        if (ans == LONG_LONG_MAX)
            ans = -1;
        cout << ans << '\n';
    }

    return 0;
}
