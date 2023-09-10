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
        lol n, m;
        cin >> n >> m;
        lol a[n][m];
        lol s = 0;
        lol mn = LONG_LONG_MAX;
        lol ng = 0;
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < m; j++)
            {
                cin >> a[i][j];
                if (a[i][j] < 0)
                {
                    ng++;
                    a[i][j] = -a[i][j];
                }
                mn = min(mn, a[i][j]);
                s += a[i][j];
            }
        }
        if (ng % 2 == 0)
            cout << s << '\n';
        else
            cout << s - 2ll * mn << '\n';
    }
}