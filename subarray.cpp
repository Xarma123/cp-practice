#include <iostream>
#include <conio.h>
using namespace std;
void SubArrays(lol a[], lol n)
{
    for (lol i = 0; i < n; i++)
    {
        for (lol j = i; j < n; j++)
        {
            for (lol k = i; k <= j; k++)
            {
                cout << a[k] << " , ";
            }
            cout << endl;
        }
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
