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
        lol dp[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            dp[i] = a[i];
        }
        for (lol i = n - 2; i >= 0; i--)
        {
            dp[i] = min(a[i], a[i] + dp[i + 1]);
        }
        lol s = 0;
        lol mn = LONG_LONG_MAX;
        lol k = 0;
        for (lol i = 0; i < n; i++)
        {
            if (dp[i] < mn)
            {
                k = s;
                mn = dp[i];
            }
            s += a[i];
        }
        cout << k << '\n';
    }
}