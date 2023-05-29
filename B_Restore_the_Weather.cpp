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
        pair<lol, lol> a[n];
        lol b[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(a, a + n);
        for (lol i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        sort(b, b + n);
        lol ans[n];
        for (lol i = 0; i < n; i++)
        {
            ans[a[i].second] = b[i];
        }
        for (lol i = 0; i < n; i++)
        {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
}