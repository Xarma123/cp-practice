#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol t;
    cin >> t;
    while (t--)
    {
        lol c, n;
        cin >> c >> n;
        if (c >= n)
            cout << n << '\n';
        else
        {
            lol mn = n / c;
            lol r = n % c;
            lol ans = 0;
            for (lol i = 0; i < r; i++)
            {
                ans += (mn + 1) * 1ll * (mn + 1);
            }
            for (lol i = 0; i < c - r; i++)
            {
                ans += (mn * 1ll * mn);
            }
            cout << ans << '\n';
        }
    }
}