#include <bits/stdc++.h>
using namespace std;
#define lol long long
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, m;
        cin >> n >> m;
        if (n >= m)
        {
            lol a[n][m];
            lol c = 1;
            for (lol i = 0; i < n; i++)
            {
                for (lol j = 0; j < m; j++)
                {
                    a[i][j] = (c++);
                }
            }
            for (lol i = 0; i < n; i += 2)
            {
                for (lol j = 0; j < m; j++)
                {
                    cout << a[i][j] << " ";
                }
                cout << '\n';
            }
            for (lol i = 1; i < n; i += 2)
            {
                for (lol j = 0; j < m; j++)
                {
                    cout << a[i][j] << " ";
                }
                cout << '\n';
            }
        }
        else
        {
            lol a[n][m];
            lol c = 1;

            for (lol j = 0; j < m; j++)
            {
                for (lol i = 0; i < n; i++)
                {
                    a[i][j] = (c++);
                }
            }
            lol b[n][m];
            lol col = 0;
            for (lol j = 0; j < m; j += 2)
            {
                for (lol i = 0; i < n; i++)
                {
                    b[i][col] = a[i][j];
                }
                col++;
            }
            for (lol j = 1; j < m; j += 2)
            {
                for (lol i = 0; i < n; i++)
                {
                    b[i][col] = a[i][j];
                }
                col++;
            }
            for (lol i = 0; i < n; i++)
            {
                for (lol j = 0; j < m; j++)
                {
                    cout << b[i][j] << " ";
                }
                cout << '\n';
            }
        }
    }
}