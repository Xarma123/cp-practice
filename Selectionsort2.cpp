#include <iostream>
#include <conio.h>
using namespace std;

void Bubblesort(lol a[], lol n)
{
    for (lol i = n-1 ; i > 0;i--)
    {
        lol key = i, max = a[i];
        for (lol j = i; j >= 0;j--)
        {
            if (a[j] > max)
            {
                max=a[j];
                key = j;
            }
        }
        swap(a[i], a[key]);
    }
    for (lol i = 0; i < n; i++)
    {
       
        cout << a[i] << endl;
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
    Bubblesort(a, n);
    getch();
    return 0;
}