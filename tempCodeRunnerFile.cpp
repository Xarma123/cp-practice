#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n;
    cin >> n;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    lol p[n];
    lol suf[n];
    for (lol i = 0; i < n; i++)
    {
        p[i] = a[i];
        if (i)
            p[i] = __gcd(p[i], p[i - 1]);
    }
    for (lol i = n - 1; i >= 0; i--)
    {
        suf[i] = a[i];
        if (i < n - 1)
            suf[i] = __gcd(suf[i], suf[i + 1]);
    }
    lol ans = LONG_LONG_MIN;
    for (lol i = 0; i < n; i++)
    {
        lol l = 0, r = 0;
        if (i)
            l = p[i - 1];
        if (i + 1 < n)
            r = suf[i + 1];
        ans = max(ans, __gcd(l, r));
    }
    cout << ans;

    return 0;
}
