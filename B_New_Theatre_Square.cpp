#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, m, x, y;
        cin >> n >> m >> x >> y;
        char s[n][m];
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < m; j++)
            {
                cin >> s[i][j];
            }
        }
        lol c2 = min(y, 2 * x);
        lol ans = 0;
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < m; j++)
            {
                if (s[i][j] == '.')
                {
                    if (j + 1 < m)
                    {
                        if (s[i][j + 1] == '.')
                        {
                            ans += c2;
                            s[i][j + 1] = '*';
                        }
                        else
                            ans += x;
                    }
                    else
                        ans += x;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}