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
        lol a[n], b[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (lol i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        sort(a, a + n);
        sort(b, b + n);
        lol ans = 1;
        lol c = 0;
        for (lol i = n - 1; i >= 0; i--)
        {
            lol v = n - (upper_bound(a, a + n, b[i]) - a) - c;
            ans = (ans * 1ll * v) % ((long long)(1e9 + 7));
            c++;
        }
        cout << ans << '\n';
    }

    return 0;
}