#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, k, q;
        cin >> n >> k >> q;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol s = -1;
        lol ans = 0;
        for (lol i = 0; i < n; i++)
        {
            if (a[i] > q)
            {
                lol l = i - s - 1;
                if (l >= k)
                {
                    ans += (l - k + 1) * 1ll * (l - k + 2) / 2ll;
                }
                s = i;
            }
        }
        lol l = n - s - 1;
        if (l >= k)
        {
            ans += (l - k + 1) * 1ll * (l - k + 2) / 2ll;
        }
        cout << ans << '\n';
    }
}