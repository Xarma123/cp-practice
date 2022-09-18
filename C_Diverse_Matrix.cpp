#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol r, c;
    cin >> r >> c;
    if (r == c && r == 1)
        cout << 0 << endl;
    else if (r == 1 || c == 1)
    {
        if (r > c)
        {
            for (lol i = 0; i < r; i++)
            {
                cout << i + 2 << endl;
            }
        }
        else
        {
            for (lol i = 0; i < c; i++)
            {
                cout << i + 2 << " ";
            }
        }
    }
    else
    {

        if (c <= r)
        {

            for (lol i = 0; i < r; i++)
            {
                lol k = 2;
                for (lol j = 0; j < c; j++)
                {
                    if (i == 0)
                        cout << k << " ";
                    else
                        cout << k * ((2 + c + i - 1)) << " ";
                    k++;
                }
                cout << endl;
            }
        }
        else
        {
            lol a[r][c];
            for (lol i = 0; i < c; i++)
            {
                lol k = 2;
                for (lol j = 0; j < r; j++)
                {
                    if (i == 0)
                        a[j][i] = k;
                    else
                        a[j][i] = k * ((2 + r + i - 1));
                    k++;
                }
            }
            for (lol i = 0; i < r; i++)
            {

                for (lol j = 0; j < c; j++)
                {
                    cout << a[i][j] << " ";
                }
                cout << endl;
            }
        }
    }

    return 0;
}