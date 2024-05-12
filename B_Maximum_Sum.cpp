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
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol m = 1e9 + 7;
        lol s = 0, mxh = 0;
        lol mx = 0;
        for (lol i = 0; i < n; i++)
        {
            mxh = max(0ll, max(s + a[i], a[i]));
            s = mxh;
            mx = max(mx, mxh);
        }
        lol olmx = mx;
        for (lol i = 0; i < k; i++)
        {
            mx = (mx * 2ll) % m;
        }
        for (lol i = 0; i < n; i++)
        {
            mx += a[i];
            mx %= m;
        }
      
        mx = ((mx - olmx) % m + m) % m;
        cout << mx << '\n';
    }
}