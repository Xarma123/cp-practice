#include <bits/stdc++.h>
using namespace std;
#define lol long long
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
        lol s = a[0];
        for (lol i = 1; i < n; i++)
        {
            s &= a[i];
        }
        if (s)
            cout << 1 << '\n';
        else
        {
            lol ans = 0;
            lol s = a[0];
            for (lol i = 1; i < n; i++)
            {
                if (s == 0)
                {
                    s = a[i];
                    ans++;
                }
                else
                    s &= a[i];
            }
            if (s == 0)
                ans++;
            cout << ans << '\n';
        }
    }
}