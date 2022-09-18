#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lol n, m;
    cin >> n >> m;
    lol a[n][m];
    lol b[n][m];
    for (lol i = 0; i < n; i++)
    {
        for (lol j = 0; j < m; j++)
        {
            a[i][j] = 1;
        }
    }
    for (lol i = 0; i < n; i++)
    {
        for (lol j = 0; j < m; j++)
        {
            cin >> b[i][j];
            if (b[i][j] == 0)
            {
                for (lol k = 0; k < n; k++)
                {
                    a[k][j] = 0;
                }
                for (lol k = 0; k < m; k++)
                {
                    a[i][k] = 0;
                }
            }
        }
    }

    bool ans = true;
    for (lol i = 0; i < n; i++)
    {
        for (lol j = 0; j < m; j++)
        {
            if (b[i][j])
            {
                bool o = false;
                for (lol k = 0; k < n; k++)
                {
                    if (a[k][j])
                        o = true;
                }
                for (lol k = 0; k < m; k++)
                {
                    if (a[i][k])
                        o = true;
                }
                if (!o)
                {
                    ans = false;
                }
            }
        }
    }
    if (ans)
    {
        cout << "YES" << endl;
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < m; j++)
            {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
        cout << "NO";

    return 0;
}