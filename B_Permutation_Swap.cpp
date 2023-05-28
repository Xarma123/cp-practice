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
        lol ans = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            ans = __gcd(ans, (long long)abs(a[i] - 1 - i));
        }
        cout << ans << '\n';
    }

    return 0;
}