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
        sort(a, a + n);
        for (lol i = 0; i < n; i++)
        {
            if (a[i] % 2 == 0 && i != n - 1)
            {
                while (a[i] % 2 == 0)
                {
                    a[i] = a[i] / 2;
                    a[n - 1] = a[n - 1] * 2;
                }
            }
        }
        sort(a, a + n);

        lol ans = 0;
        lol x = INT_MAX;
        for (lol i = 0; i < n; i++)
        {
            ans += a[i];
            if (a[i] % 2 != 0)
                x = i;
        }
        lol s = ans;
        while (a[n - 1] % 2 == 0 && x != INT_MAX)
        {
            s -= a[n - 1];
            s -= a[x];
            a[x] = a[x] * 2;
            a[n - 1] = a[n - 1] / 2;
            s += a[n - 1];
            s += a[x];
            ans=max(ans,s);
        }

        cout << ans << endl;
    }

    return 0;
}