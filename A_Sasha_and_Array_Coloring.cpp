#include <bits/stdc++.h>
using namespace std;
#define lol long long
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
        sort(a, a + n);
        lol ans = 0;
        for (lol i = 0; i < n / 2; i++)
        {
            ans += a[n - 1 - i] - a[i];
        }
        cout << ans << '\n';
    }
}