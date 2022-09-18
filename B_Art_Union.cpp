#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol m, n;
    cin >> m >> n;
    lol t[m][n];
    for (lol i = 0; i < m; i++)
    {
        for (lol j = 0; j < n; j++)
        {
            cin >> t[i][j];
        }
    }

    for (lol i = 0; i < m; i++)
    {
        for (lol j = 0; j < n; j++)
        {
            if (i == 0)
            {
                if (j != 0)
                    t[i][j] = t[i][j - 1] + t[i][j];
            }
            else
            {
                lol x = t[i - 1][j];
                if (j - 1 >= 0)
                    x = max(t[i][j - 1], x);
                t[i][j] = t[i][j] + x;
            }
        }
    }
    for (lol i = 0; i < m; i++)
    {
        cout << t[i][n - 1] << " ";
    }

    return 0;
}