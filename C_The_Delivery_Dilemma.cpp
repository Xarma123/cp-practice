#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n;
        cin >> n;
        pair<lol, lol> a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i].first;
        }
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i].second;
        }
        sort(a, a + n);
        lol ans = a[n - 1].first;
      
        lol t = a[n - 1].second;
        for (lol i = n - 2; i >= 0; i--)
        {
            ans = min(ans, max(a[i].first, t));
            t += a[i].second;
        }
        ans = min(ans, t);
        cout << ans << endl;
    }

    return 0;
}