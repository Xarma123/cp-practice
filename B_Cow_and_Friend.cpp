#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, x;
        cin >> n >> x;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol ans = LONG_LONG_MAX;
        for (lol i = 0; i < n; i++)
        {
            ans = min(ans, max(2ll, ((a[i] + x - 1) / a[i])));
            if (a[i] == x)
                ans = 1;
        }
        cout << ans << '\n';
    }
}