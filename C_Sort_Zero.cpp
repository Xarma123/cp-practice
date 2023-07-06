#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        lol a[n];
        lol ans = LONG_LONG_MAX;
        lol rr[n + 1];

        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];

            rr[a[i]] = i;
        }

        lol mxrr = -1;
        set<lol> x;
        bool c[n + 1];
        memset(c, false, sizeof(c));
        c[n] = true;
        c[n - 1] = true;
        for (lol i = n - 2; i >= 0; i--)
        {
            if (a[i] > a[i + 1])
                break;
            c[i] = true;
        }
        if (c[0])
            ans = 0;
        for (lol i = 0; i < n; i++)
        {
            mxrr = max(mxrr, rr[a[i]]);
            x.insert(a[i]);
            if (mxrr <= i && c[i + 1])
            {
                ans = min(ans, (long long)x.size());
            }
        }
        cout << ans << '\n';
    }
}