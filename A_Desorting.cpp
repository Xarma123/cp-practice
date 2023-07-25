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
        lol n;
        cin >> n;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol ans = LONG_LONG_MAX;
        for (lol i = 0; i < n - 1; i++)
        {
            lol v = a[i + 1] - a[i];
            if (v < 0)
                ans = 0;
            else
                ans = min(ans, (long long)((v / 2ll) + 1));
        }
        cout << ans << '\n';
    }
}