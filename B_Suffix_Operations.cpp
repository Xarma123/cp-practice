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
        lol mx = INT_MIN;
        lol t = 0;
        for (lol i = 1; i < n; i++)
        {

            t += abs(a[i] - a[i - 1]);
        }
        lol ans = min(t - abs(a[0] - a[1]), t - abs(a[n - 1] - a[n - 2]));
        for (lol i = 1; i < n - 1; i++)
        {
            ans = min(ans, t - (abs(a[i] - a[i - 1]) + abs(a[i + 1] - a[i])) + abs(a[i + 1] - a[i - 1]));
        }
        cout << ans << endl;
    }

    return 0;
}