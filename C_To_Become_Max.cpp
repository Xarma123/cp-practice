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
        lol n, k;
        cin >> n >> k;
        lol a[n];
        lol b[n];

        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];

            b[i] = a[i];
        }
        lol s = 0, e = 1e18;
        while (s != e - 1)
        {
            lol m = (s + e) / 2ll;
            lol mnc = LONG_LONG_MAX;
            for (lol i = 0; i < n; i++)
            {
                lol c = 0;
                for (lol j = i; j < n; j++)
                {
                    if (a[j] >= m - (j - i))
                        break;
                    else if (j == n - 1)
                    {
                        c = LONG_LONG_MAX;
                        break;
                    }
                    else
                    {
                        c += (m - (j - i)) - a[j];
                    }
                }
                mnc = min(mnc, c);
            }
            if (mnc <= k)
                s = m;
            else
                e = m;
        }
        cout << s << '\n';
    }
}