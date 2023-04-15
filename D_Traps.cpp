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
        lol ans = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            ans += a[i];
            a[i] = a[i] - (n - i - 1);
        }
        sort(a, a + n);
        for (lol i = n - 1; i >= n - 1 - k + 1; i--)
        {
            ans -= a[i];
        }
        for (lol i = k - 1; i >= 0; i--)
        {
            ans -= i;
        }
        cout << ans << '\n';
    }

    return 0;
}