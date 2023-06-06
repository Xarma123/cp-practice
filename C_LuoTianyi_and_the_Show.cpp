#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, m;
        cin >> n >> m;
        lol a[n];
        lol oc[m + 1];
        memset(oc, 0, sizeof(oc));
        lol l = 0, r = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] > 0)
                oc[a[i]] = 1;
            else if (a[i] == -1)
                l++;
            else
                r++;
        }
        for (lol i = 1; i <= m; i++)
        {
            oc[i] += oc[i - 1];
        }
        lol ans = max(min(l + oc[m], m), min(r + oc[m], m));
        for (lol i = 0; i < n; i++)
        {
            if (a[i] > 0)
            {

                lol ll = max(a[i] - l - oc[a[i] - 1], 1ll);
                lol rr = min(a[i] + r + oc[m] - oc[a[i]], m);
                ans = max(ans, rr - ll + 1 );
            }
        }
        cout << ans << '\n';
    }
}