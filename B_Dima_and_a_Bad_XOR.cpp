#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
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
    bool win = false;
    for (lol pokemon = 0; pokemon < 12; pokemon++)
    {
        lol onlyodd = 0, oneodd = 0;
        for (lol i = 0; i < n; i++)
        {
            lol o = 0;
            for (lol j = 0; j < m; j++)
            {
                if (a[i][j] % 2 != 0)
                    o++;
            }
            if (o == m)
                onlyodd++;
            else if (o >= 1)
                oneodd++;
        }
        if (onlyodd % 2 != 0)
        {
            win = true;
            cout << "TAK" << endl;
            for (lol i = 0; i < n; i++)
            {
                lol o = 0;
                for (lol j = 0; j < m; j++)
                {
                    if (a[i][j] % 2 != 0)
                        o++;
                }
                if (o == m)
                {
                    cout << 1 << " ";
                }
                else
                {
                    for (lol j = 0; j < m; j++)
                    {
                        if (a[i][j] % 2 == 0)
                        {
                            cout << j + 1 << " ";
                            break;
                        }
                    }
                }
            }
        }
        else if (oneodd >= 1)
        {
            cout << "TAK" << endl;
            win = true;
            bool q = false;
            for (lol i = 0; i < n; i++)
            {
                lol o = 0;
                for (lol j = 0; j < m; j++)
                {
                    if (a[i][j] % 2 != 0)
                        o++;
                }
                if (o == m)
                {
                    cout << 1 << " ";
                }
                else if (!q && o > 0)
                {
                    for (lol j = 0; j < m; j++)
                    {

                        if (a[i][j] % 2 != 0)
                        {
                            cout << j + 1 << " ";
                            q = true;
                            break;
                        }
                    }
                }
                else
                {
                    for (lol j = 0; j < m; j++)
                    {

                        if (a[i][j] % 2 == 0)
                        {
                            cout << j + 1 << " ";
                            break;
                        }
                    }
                }
            }
        }
        for (lol i = 0; i < n; i++)
        {
            for (lol j = 0; j < m; j++)
            {
                a[i][j] /= 2;
            }
        }

        if (win)
        {

            break;
        }
    }
    if (!win)
        cout << "NIE";

    return 0;
}