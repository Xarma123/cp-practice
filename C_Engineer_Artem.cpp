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
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < m; j++)
            {
                if (i % 2 == 0)
                {
                    if (j % 2 == 0)
                    {
                        if (a[i][j] % 2)
                            a[i][j]++;
                    }
                    else
                    {
                        if (a[i][j] % 2 == 0)
                            a[i][j]++;
                    }
                }
                else
                {
                    if (j % 2 != 0)
                    {
                        if (a[i][j] % 2)
                            a[i][j]++;
                    }
                    else
                    {
                        if (a[i][j] % 2 == 0)
                            a[i][j]++;
                    }
                }
            }
        }
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < m; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << '\n';
        }
        
    }

    return 0;
}