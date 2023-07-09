#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
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
        lol b[n - 1];
        for (lol i = 1; i < n; i++)
        {
            b[i - 1] = abs(a[i] - a[i - 1]);
        }
        sort(b, b + n - 1);
        lol ans = 0;
        for (lol i = 0; i < n - k; i++)
        {
            ans += b[i];
        }
        cout << ans << '\n';
    }
}