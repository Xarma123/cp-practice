#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol a, b, c, d, e, f;
        cin >> a >> b >> c >> d >> e >> f;
        lol ans = 0;
        if ((a > c && a > e) || (a < c && a < e))
        {
            ans += min((long long)abs(a - c), (long long)abs(a - e));
        }
        if ((b > d && b > f) || (b < d && b < f))
        {
            ans += min((long long)abs(b - d), (long long)abs(b - f));
        }
        cout << ans + 1 << '\n';
    }
}