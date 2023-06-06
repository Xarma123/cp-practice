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
        lol a[(n * 1ll * m)];
        for (lol i = 0; i < n * 1ll * m; i++)
        {
            cin >> a[i];
        }
        sort(a, a + (n * 1ll * m));
        lol ans = a[n * 1ll * m - 1] * 1ll * (n * 1ll * m - 1) -
                  min((n - 1) * 1ll * a[0] + n * 1ll * (m - 1) * 1ll * a[1],
                      min((n - 1) * 1ll * a[1] + n * 1ll * (m - 1) * 1ll * a[0],
                          min((m - 1) * 1ll * a[0] + m * 1ll * (n - 1) * 1ll * a[1],
                              (m - 1) * 1ll * a[1] + m * 1ll * (n - 1) * 1ll * a[0])));

        lol l = n * 1ll * m - 1;
        lol ans2 = a[0] * 1ll * (1 - n * 1ll * m) +
                   max((n - 1) * 1ll * a[l] + n * 1ll * (m - 1) * 1ll * a[l - 1],
                       max((n - 1) * 1ll * a[l - 1] + n * 1ll * (m - 1) * 1ll * a[l],
                           max((m - 1) * 1ll * a[l] + m * 1ll * (n - 1) * 1ll * a[l - 1],
                               (m - 1) * 1ll * a[l - 1] + m * 1ll * (n - 1) * 1ll * a[l])));
        cout << max(ans, ans2) << '\n';
    }
}