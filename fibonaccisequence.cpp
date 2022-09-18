#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
    lol n;
    cin >> n;

    lol a = 0, b = 1, c = a + b;
    if (n == 1)
    {
        cout << a;
    }
    else if (n == 2)
    {
        cout << b;
    }
    else
    {

        for (lol i = 0; i < n - 3; i++)
        {
            /* code */ a = b;
            b = c;
            c = a + b;
        }

        cout << c;
    }

    getch();
    return 0;
}