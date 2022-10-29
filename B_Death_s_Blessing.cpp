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
        lol ans = 0;
        lol mx = LONG_LONG_MIN;
        for (lol i = 0; i < n; i++)
        {
            lol q;
            cin >> q;
            ans += q;
        }
        for (lol i = 0; i < n; i++)
        {
            lol q;
            cin >> q;
            ans += q;
            mx = max(mx, q);
        }
        ans -= mx;
        cout << ans << endl;
    }

    return 0;
}