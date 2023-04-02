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
        lol n, k;
        cin >> n >> k;
        lol a[n];
        for (lol i = 0; i < n; i++)
            cin >> a[i];
        lol ans = LONG_LONG_MAX;
        for (lol i = 0; i <= a[0]; i++)
        {

            lol mn = LONG_LONG_MAX;
            lol mx = LONG_LONG_MIN;
            for (lol j = 0; j < n; j++)
            {
                if (i == 0)
                {
                    mn = min(mn, a[j] / k);
                    mx = max(mx, a[j] / k);
                }
                else
                {
                    lol d = a[j] / i;
                    d = min(d, k);
                    mn = min(mn, a[j] / d);
                    mx = max(mx, a[j] / d);
                }
            }
            ans = min(ans, mx - mn);
        }
        cout << ans << '\n';
    }

    return 0;
}