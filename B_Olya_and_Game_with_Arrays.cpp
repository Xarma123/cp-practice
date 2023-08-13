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
        lol mn = LONG_LONG_MAX;
        lol ans = 0;
        lol mn2 = LONG_LONG_MAX;
        for (lol i = 0; i < n; i++)
        {
            lol m;
            cin >> m;
            lol b[m];
            for (lol j = 0; j < m; j++)
            {
                cin >> b[j];
            }
            sort(b, b + m);
            mn = min(mn, b[0]);
            ans += b[1];
            mn2 = min(mn2, b[1]);
        }
        ans -= mn2;
        ans += mn;
        cout << ans << '\n';
    }
}