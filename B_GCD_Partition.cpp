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
        lol s = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            s += a[i];
        }
        lol c = 0;
        lol ans = 0;
        for (lol i = 0; i < n - 1; i++)
        {
            c += a[i];
            ans = max(ans, __gcd(c, s - c));
        }
        cout << ans << '\n';
    }

    return 0;
}