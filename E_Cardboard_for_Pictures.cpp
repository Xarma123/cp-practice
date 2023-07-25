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
        lol mx = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            mx = max(mx, a[i]);
        }

        lol s = 0, e = (long long)ceill((ceill(sqrtl(c)) - mx) / (long double)2) + 2ll;
        while (s != e - 1)
        {
            lol m = (s + e) / 2;
            lol ww = 0;
            for (lol i = 0; i < n; i++)
            {
                ww += (a[i] + 2ll * m) * 1ll * (a[i] + 2ll * m);
                if (ww > c)
                    break;
            }
            if (ww <= c)
                s = m;
            else
                e = m;
        }
        cout << s << '\n';
    }
}