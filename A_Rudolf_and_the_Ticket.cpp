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
        lol n, m, k;
        cin >> n >> m >> k;
        lol b[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        lol c[m];
        for (lol i = 0; i < m; i++)
        {
            cin >> c[i];
        }
        sort(c, c + m);
        lol ans = 0;
        for (lol i = 0; i < n; i++)
        {
            lol j = upper_bound(c, c + m, k - b[i]) - c;
            ans += j;
        }
        cout << ans << '\n';
    }

    return 0;
}
