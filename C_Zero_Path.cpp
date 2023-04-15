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
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }
        if ((n + m) % 2 == 0)
        {
            cout << "NO\n";
            continue;
        }
        lol mn[n][m];
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < m; j++)
            {
                if (i == 0 && j == 0)
                {
                    mn[i][j] = a[i][j];
                }
                else if (i == 0)
                {
                    mn[i][j] = mn[i][j - 1] + a[i][j];
                }
                else if (j == 0)
                {
                    mn[i][j] = mn[i - 1][j] + a[i][j];
                }
                else
                {
                    mn[i][j] = min(mn[i - 1][j], mn[i][j - 1]) + a[i][j];
                }
            }
        }
        lol mx[n][m];
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < m; j++)
            {
                if (i == 0 && j == 0)
                {
                    mx[i][j] = a[i][j];
                }
                else if (i == 0)
                {
                    mx[i][j] = mx[i][j - 1] + a[i][j];
                }
                else if (j == 0)
                {
                    mx[i][j] = mx[i - 1][j] + a[i][j];
                }
                else
                {
                    mx[i][j] = max(mx[i - 1][j], mx[i][j - 1]) + a[i][j];
                }
            }
        }
        if (mn[n - 1][m - 1] <= 0 && mx[n - 1][m - 1] >= 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}