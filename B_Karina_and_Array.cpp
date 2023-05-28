#include <bits/stdc++.h>
#define lol long long
using namespace std;
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
        lol ans = LONG_LONG_MIN;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] == 0)
                ans = 0;
        }
        sort(a, a + n);
        ans = max(ans, max(a[0] * 1ll * a[1], a[n - 1] * 1ll * a[n - 2]));
        ans = max(ans, a[0] * 1ll * a[n - 1]);
        cout << ans << '\n';
    }

    return 0;
}