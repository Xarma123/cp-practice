#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol n, k;
    cin >> n >> k;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lol ans = LONG_LONG_MIN;
    for (lol b = 0; b < n; b++)
    {
        lol su = 0;
        for (lol i = 0; i < n; i++)
        {
            if ((abs(b - i) % k != 0))
                su += a[i];
        }
        if (su < 0)
            su = -su;
        ans = max(ans, su);
    }
    cout << ans;

    return 0;
}