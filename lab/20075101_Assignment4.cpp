#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lol x, y;
    cin >> x >> y;
    lol suf[n];
    lol ans = LONG_LONG_MAX;
    for (lol i = n - 1; i >= 0; i--)
    {
        suf[i] = a[i];
        if (i + y < n)
            suf[i] += suf[i + y];
        if (i + (x - 1) * 1ll * y < n)
        {
            if (i + x * 1ll * y < n)
            {
                ans = min(ans, suf[i] - suf[i + x * 1ll * y]);
            }
            else
                ans = min(ans, suf[i]);
        }
    }
    cout << ans;

    return 0;
}
