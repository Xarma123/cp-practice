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
        lol n, m;
        cin >> n >> m;
        lol a[n][m];
        lol mx = LONG_LONG_MIN;
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < m; j++)
            {
                cin >> a[i][j];
                mx = max(mx, a[i][j]);
            }
        }

        for (lol i = 0; i < n; i++)
        {

            for (lol j = 0; j < m; j++)
            {
                if (a[i][j] == mx)
                {
                    lol x = max(i + 1, n - i);
                    lol y = max(j + 1, m - j);
                    cout << x * y << endl;
                    ;

                    break;
                }
            }
        }
    }

    return 0;
}