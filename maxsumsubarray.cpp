#include <iostream>
#include <conio.h>
#include <climits>
using namespace std;
void SubArrays(lol a[], lol n)
{
    lol max = INT_MIN;
    lol x;
    lol b[10];

    for (lol i = 0; i < n; i++)
    {
        for (lol j = i; j < n; j++)
        {
            lol s = 0;
            for (lol k = i; k <= j; k++)
            {
                s = s + a[k];
            }
            if (s > max)
            {
                max = s;
                x = j - i + 1;
                lol z = 0;
                for (lol g = i; g <= j; g++)
                {
                    b[x];
                    b[z] = a[g];
                    z++;
                }
            }
        }
    }
    cout << max << endl;
    for (lol o = 0; o < x; o++)
    {
        cout << b[o] << " ,";
    }
}

int main()
{
    lol n;
    cin >> n;
    lol a[n];
    for (lol i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    SubArrays(a, n);
    getch();
    return 0;
}
