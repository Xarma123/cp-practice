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
        lol n, x;
        cin >> n >> x;
        lol a[n];
        lol ans = 0;
        lol l = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            ans = max(ans, a[i] - l);
            l = a[i];
        }
        ans = max(ans, 2ll * (x - l));
        cout << ans << '\n';
    }

    return 0;
}
