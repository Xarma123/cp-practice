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
        lol mx = INT_MIN;
        lol s1 = 0;
        bool flag = false;
        for (lol i = 0; i < n; i++)
        {

            cin >> a[i];
            if (a[i] == 0)
                flag = true;
            mx = max(mx, a[i]);
            s1 += a[i];
        }
        if (flag)
        {
            lol ans = 0;
            for (lol i = 0; i < n; i++)
            {
                ans += mx - a[i];
            }
            cout << ans - mx << endl;
        }
        else
        {
            lol s = s1;
            if (s % (n - 1) != 0)
                s += n - 1 - s % (n - 1);

            lol k = 0;
            if (s / (n - 1) < mx)
                k = ceil((long double)(mx * (n - 1) - s) / (long double)(n - 1));

            s += k * (n - 1);
            cout << s - s1 << endl;
        }
    }

    return 0;
}