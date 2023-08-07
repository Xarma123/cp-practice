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
        lol n, c;
        cin >> n >> c;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol b[n - 1];
        for (lol i = 0; i < n - 1; i++)
        {
            cin >> b[i];
        }

        lol ans = LONG_LONG_MAX;
        lol d = 0, ex = 0;
        for (lol i = 0; i < n; i++)
        {
            lol k = ceil((c - ex) / (long double)a[i]);
            ans = min(ans, k + d);
            if (i < n - 1)
            {x
                k = ceil((b[i] - ex) / (long double)a[i]);
                d += k + 1;
                ex += k * 1ll * a[i];
                ex -= b[i];
            }
        }
        cout << ans << '\n';
    }
}