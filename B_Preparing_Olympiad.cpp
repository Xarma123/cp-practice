#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n, l, r, x;
    cin >> n >> l >> r >> x;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lol ans = 0;
    for (lol i = 0; i < (long long)pow(2, n); i++)
    {
        lol s = 0, c = 0, minn = LONG_LONG_MAX, maxx = LONG_LONG_MIN;
        for (lol j = 0; j < n; j++)
        {
            if ( i & (1 << j))
            {
                c++;
                s += a[j];
                minn = min(minn, a[j]);
                maxx = max(maxx, a[j]);
            }
        }

        if (c >= 2)
        {
            if (maxx - minn >= x)
            {
                if (s >= l && s <= r)
                    ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}