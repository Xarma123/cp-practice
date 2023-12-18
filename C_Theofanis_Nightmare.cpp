#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    ios_base::sync_with_stdio(false);
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
        lol ans = 0;
        lol p = 0;
        for (lol i = n - 1; i >= 0; i--)
        {
            ans = max(ans + a[i], ans + p + a[i]);
            p += a[i];
        }
        cout << ans << '\n';
    }

    return 0;
}
