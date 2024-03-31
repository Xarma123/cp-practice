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
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (lol i = 1; i < n; i++)
        {
            a[i] += a[i - 1];
        }
        lol q;
        cin >> q;
        while (q--)
        {
            lol l, u;
            cin >> l >> u;
            l--;
            lol s = l - 1, e = n;
            while (s != e - 1)
            {
                lol m = (s + e) / 2ll;
                if (m == l - 1)
                    s = m;
                else if (m == n)
                    e = m;
                else
                {
                    lol sum = a[m];
                    if (l - 1 >= 0)
                        sum -= a[l - 1];
                    if (sum <= u)
                        s = m;
                    else
                        e = m;
                }
            }
            if (s == l - 1)
            {
                cout << l + 1 << ' ';
            }
            else
            {
                lol sum1 = a[s];
                if (l - 1 >= 0)
                    sum1 -= a[l - 1];
                sum1 = sum1 * 1ll * u - ((sum1 * 1ll * (sum1 - 1)) / 2ll);
                lol sum2 = LONG_LONG_MIN;
                if (e < n)
                {
                    sum2 = a[e];
                    if (l - 1 >= 0)
                        sum2 -= a[l - 1];
                    sum2 = sum2 * 1ll * u - ((sum2 * 1ll * (sum2 - 1)) / 2ll);
                }
                if (sum1 >= sum2)
                    cout << s + 1 << ' ';
                else
                    cout << e + 1 << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}
