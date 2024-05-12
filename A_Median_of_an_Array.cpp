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
        sort(a, a + n);
        lol j = ((n + 1) / 2ll) - 1;
        lol v = a[j] + 1;
        lol ans = 1;
        j++;
        while (j < n && a[j] < v)
        {
            ans += v - a[j];
            j++;
        }
        cout << ans << '\n';
    }

    return 0;
}
