#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while (1)
    {
        lol n, m;
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        lol c[n + 1][n + 1];
        for (lol i = 0; i <= n; i++)
        {
            for (lol j = 0; j <= n; j++)
            {
                if (i == j)
                {
                    c[i][j] = 1;
                }
                else if (i < j)
                    c[i][j] = -1;
                else if (j == 0)
                    c[i][j] = 1;
                else
                {
                    c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
                }
            }
        }
        cout << n << " things taken " << m << " at a time is " << c[n][m] << " exactly." << endl;
    }
    return 0;
}