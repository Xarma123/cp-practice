#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    lol a[3][3] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    lol s[3][3] = {0};
    for (lol i = 0; i < 3; i++)
    {
        for (lol j = 0; j < 3; j++)
        {
            cin >> s[i][j];
        }
    }

    for (lol i = 0; i < 3; i++)
    {
        for (lol j = 0; j < 3; j++)
        {
            while (s[i][j]--)
            {

                if (j - 1 >= 0)
                {
                    // if (i - 1 >= 0)
                    // {
                    //     a[i - 1][j - 1] = 1 - a[i - 1][j - 1];
                    // }

                    a[i][j - 1] = 1 - a[i][j - 1];

                    // if (i + 1 < 3)
                    // {
                    //     a[i + 1][j - 1] = 1 - a[i + 1][j - 1];
                    // }
                }
                if (i - 1 >= 0)
                {
                    a[i - 1][j] = 1 - a[i - 1][j];
                }

                if (i + 1 < 3)
                {
                    a[i + 1][j] = 1 - a[i + 1][j];
                }
                if (j + 1 < 3)
                {
                    // if (i - 1 >= 0)
                    // {
                    //     a[i - 1][j + 1] = 1 - a[i - 1][j + 1];
                    // }

                    a[i][j + 1] = 1 - a[i][j + 1];

                    // if (i + 1 < 3)
                    // {
                    //     a[i + 1][j + 1] = 1 - a[i + 1][j + 1];
                    // }
                }
                a[i][j] = 1 - a[i][j];
            }
        }
    }  



     for (lol i = 0; i < 3; i++)
                {
                    for (lol j = 0; j < 3; j++)
                    {
                        cout << a[i][j];
                    }
                    cout << endl;
                }  
}