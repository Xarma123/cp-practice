#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol n, k;
        cin >> n >> k;
        lol t = ceil(n / ((long double)2));
        if (k <= t)
        {
            char a[n][n];
            for (lol i = 0; i < n; i++)
            {
                for (lol j = 0; j < n; j++)
                {
                    a[i][j] = '.';
                }
            }
            lol x = 0, y = 0;
            while (k--)
            {
                a[x][y] = 'R';
                x += 2;
                y += 2;
            }
            for (lol i = 0; i < n; i++)
            {
                for (lol j = 0; j < n; j++)
                {
                    cout << a[i][j];
                }
                cout << endl;
            }
        }
        else
            cout << -1<<endl;
    }

    return 0;
}