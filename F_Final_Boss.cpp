#include <bits/stdc++.h>
using namespace std;
#define lol unsigned long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol h, n;
        cin >> h >> n;
        lol a[n], c[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (lol i = 0; i < n; i++)
        {
            cin >> c[i];
        }
        lol s = 0, e = 1e15;
        while (s != e - 1)
        {
            lol m = (s + e) / 2ll;
            if (m == 0)
            {
                s = 0;
                continue;
            }
            lol d = 0;
            for (lol i = 0; i < n; i++)
            {
                lol k = ((m - 1) / c[i]) + 1;
                d += a[i] * 1ll * (k);
            }
            if (d >= h)
            {
                e = m;
            }
            else
                s = m;
        }
        cout << e << '\n';
    }

    return 0;
}
