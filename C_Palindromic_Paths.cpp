#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, m;
        cin >> n >> m;
        lol a[n][m];
        for (lol i = 0; i < n; i++)
            for (lol j = 0; j < m; j++)
                cin >> a[i][j];
        lol c[n + m - 1][2];
        for (lol i = 0; i <= n + m - 2; i++)
        {
            c[i][0] = 0;
            c[i][1] = 0;
        }

        for (lol i = 0; i < n; i++)
            for (lol j = 0; j < m; j++)
                c[i + j][a[i][j]]++;
        lol ans = 0;
        for (lol i = 0; i < n + m - 2 - i; i++)
        {
            lol j = n + m - 2 - i;

            ans += min(c[i][0] + c[j][0], c[i][1] + c[j][1]);
        }
        cout << ans << endl;
    }

    return 0;
}