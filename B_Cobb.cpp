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
        lol n, k;
        cin >> n >> k;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lol ans = LONG_LONG_MIN;
        for (lol i = max(n - 300, 0ll); i < n; i++)
        {
            for (lol j = i + 1; j < n; j++)
            {
                ans = max(ans, (i + 1) * 1ll * (j + 1) - k * 1ll * (a[i] | a[j]));
            }
        }
        cout << ans << '\n';
    }

    return 0;
}