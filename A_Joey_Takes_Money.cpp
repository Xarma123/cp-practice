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
        lol ans = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            ans += a[i];
        }
        sort(a, a + n);
        while (a[n - 2] > 1)
        {
            ans += a[n - 1] * 1ll * a[n - 2];
            ans++;
            ans -= a[n - 1];
            ans -= a[n - 2];
            a[n - 1] = a[n - 1] * 1ll * a[n - 2];
            a[n - 2] = 1;
            sort(a, a + n);
        }
        cout << ans*2022ll << endl;
    }

    return 0;
}