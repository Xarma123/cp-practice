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
        lol n;
        cin >> n;
        lol a[n];
        lol ev = 0;
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] % 2 == 0)
                ev++;
        }
        if (ev == ((n + 1) / 2ll))
        {
            lol ans = 0;
            for (lol i = 0; i < n; i += 2)
            {
                ans += (a[i] % 2);
            }
            cout << ans << '\n';
        }
        else
            cout << -1 << '\n';
    }
}