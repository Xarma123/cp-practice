#include <iostream>
#include <conio.h>
using namespace std;
void sortingarray(lol a[], lol n)
{
    for (lol j = 0; j < n - 1; j++)
    {
        lol min = a[j];
        lol key = j;
        for (lol i = j; i < n; i++)
        {
            if (a[i] < min)
            {
                min = a[i];
                key = i;
            }
        }
        swap(a[key], a[j]);
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
    sortingarray(a, n);
    for (lol i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
    getch();

    return 0;
}
