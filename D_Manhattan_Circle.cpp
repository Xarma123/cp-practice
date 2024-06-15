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
        lol n, m;
        cin >> n >> m;
        char a[n][m];
        lol x = -1, y = -1;
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < m; j++)
            {
                cin >> a[i][j];
                if (a[i][j] == '#' && y == -1)
                {
                    y = j + 1;
                }
            }
        }
        for (lol j = 0; j < m; j++)
        {
            for (lol i = 0; i < n; i++)
            {
                if (a[i][j] == '#' && x == -1)
                {
                    x = i + 1;
                }
            }
        }
        cout << x << " " << y << '\n';
    }

    return 0;
}
