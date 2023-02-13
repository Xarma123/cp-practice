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
        lol n, w, h;
        cin >> n >> w >> h;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol b[n];
        lol mn = LONG_LONG_MIN;
        lol mx = LONG_LONG_MAX;
        bool f = true;
        for (lol i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        sort(a, a + n);
        sort(b, b + n);
        for (lol i = 0; i < n; i++)
        {

            lol z = b[i] - a[i] + w - h;
            lol z2 = b[i] - a[i] + h - w;
            if (z2 > z)
            {
                swap(z, z2);
            }

            if (mn > z || mx < z2)
            {
                f = false;
            }
            else
            {
                mn = max(mn, z2);
                mx = min(mx, z);
            }
        }
        if (f)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }

    return 0;
}