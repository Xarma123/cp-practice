#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, m, r, c;
        cin >> n >> m >> r >> c;
        string a[n];
        for (lol i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        bool black = false;
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < m; j++)
            {
                if (a[i][j] == 'B')
                {
                    black = true;
                    break;
                }
            }
        }
        bool b = false;
        for (lol i = 0; i < n; i++)
        {
            if (a[i][c - 1] == 'B')
            {
                b = true;
                break;
            }
        }
        for (lol i = 0; i < m; i++)
        {
            if (a[r - 1][i] == 'B')
            {
                b = true;
                break;
            }
        }

        if (a[r - 1][c - 1] == 'B')
        {
            cout << 0 << endl;
        }
        else if (b)
        {
            cout << 1 << endl;
        }
        else if (black)
        {
            cout << 2 << endl;
        }
        else
            cout << -1 << endl;
    }

    return 0;
}