#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
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
        lol op = 0;
        for (lol i = 0; i < n; i++)
        {
            lol mx = 0;
            if (i + 1 < n)
            {
                mx = max(mx, a[i + 1]);
            }
            if (i - 1 >= 0)
                mx = max(mx, a[i - 1]);
            if (mx <= a[i])
            {

                op += a[i] - mx;
                a[i] = mx;
            }
        }
        lol ans = op;
        for (lol i = 0; i < n; i++)
        {
            lol l = a[i], r = a[i];
            if (i - 1 >= 0)
            {
                if (a[i - 1] <= a[i])
                {
                    l = a[i] - a[i - 1];
                }
                else
                    l = 0;
            }
            if (i + 1 < n)
            {
                if (a[i + 1] <= a[i])
                {
                    r = a[i] - a[i + 1];
                }
                else
                    r = 0;
            }
            ans += l;
            ans += r;
        }
        cout << ans << endl;
    }

    return 0;
}