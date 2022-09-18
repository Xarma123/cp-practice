#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol m;
        cin >> m;
        lol a[2][m];
        lol cs1[m];
        lol cs2[m];

        for (lol i = 0; i < 2; i++)
        {
            for (lol j = 0; j < m; j++)
            {

                cin >> a[i][j];
                if (i == 0)
                {
                    if (j == 0)
                        cs1[j] = a[i][j];
                    else
                    {
                        cs1[j] = cs1[j - 1] + a[i][j];
                    }
                }
                else
                {
                    if (j == 0)
                        cs2[j] = a[i][j];
                    else
                    {
                        cs2[j] = cs2[j - 1] + a[i][j];
                    }
                }
            }
        }
        lol ans = 0;

        for (lol i = ; i < m; i++)
        {
            lol below;
            if (i != 0)
                below = cs2[i - 1];
            else
                below = 0;
            lol above = cs1[m - 1] - cs1[i];
            ans = max(ans, max(below, above));
        }
        cout << ans << endl;
    }

    return 0;
}