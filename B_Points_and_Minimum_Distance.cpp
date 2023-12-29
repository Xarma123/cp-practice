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
        n = n * 2ll;
        lol a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        lol ans = 0;
        for (lol i = 1; i < n / 2ll; i++)
        {
            ans += a[i] - a[i - 1];
        }
        for (lol i = (n / 2ll) + 1; i < n; i++)
        {
            ans += a[i] - a[i - 1];
        }
        cout << ans << '\n';
        for (lol i = 0; i < n / 2ll; i++)
        {
            cout << a[i] << ' ' << a[i + n / 2ll] << '\n';
        }
    }

    return 0;
}
