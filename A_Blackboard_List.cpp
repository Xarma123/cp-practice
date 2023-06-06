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
        lol mn = LONG_LONG_MAX, mx = LONG_LONG_MIN;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            mn = min(mn, a[i]);
            mx = max(mx, a[i]);
        }
        if (mn < 0)
            cout << mn << '\n';
        else
            cout << mx << '\n';
    }
}