#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, k;
        cin >> n >> k;

       
        lol a[n + 1];
        memset(a, 0, sizeof(a));
        lol c = 0;
        for (lol i = 1; i <= n; i++)
        {
            lol l = (long long)ceill(i / (long double)k);
            if (c < l)
                a[i] = 1, c++;
        }
        c = 0;
        for (lol i = n; i >= 1; i--)
        {
            c += a[i];
            lol l = (long long)ceill((n + 1 - i) / (long double)k);
            if (c < l)
                a[i] = 1, c++;
        }
        lol ans = 0;
        for (lol i = 1; i <= n; i++)
        {
            ans += a[i];
        }
        cout << ans << '\n';
    }
}