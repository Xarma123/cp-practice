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
        lol n, m;
        cin >> n >> m;
        lol a[n];

        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        if (n == 2)
        {
            cout << -1 << '\n';
        }
        else if (m < n)
        {
            cout << -1 << '\n';
        }
        else
        {
            lol mn = -1, mn2 = -1;
            lol c = 0;
            for (lol i = 0; i < n; i++)
            {
                c += 2ll * a[i];
                if (mn == -1)
                {
                    mn = i;
                }
                else if (a[i] <= a[mn])
                {
                    mn2 = mn;
                    mn = i;
                }
                else if (mn2 == -1)
                {
                    mn2 = i;
                }
                else if (a[i] < a[mn2])
                {
                    mn2 = i;
                }
            }
            c += (m - n) * 1ll * (a[mn] + a[mn2]);
            cout << c << '\n';
            for (lol i = 1; i <= n; i++)
            {
                if (i < n)
                    cout << i << " " << i + 1 << '\n';
                else
                    cout << 1 << " " << n << '\n';
            }
            m -= n;
            while (m--)
            {
                cout << mn + 1 << " " << mn2 + 1 << '\n';
            }
        }
    }
}