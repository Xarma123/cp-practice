#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
    
    for (lol r = 0; r < 5; r++)
    {  char a = 'A';
        for (lol i = 0; i < 5 - r; i++)
        {
            cout << a;
            a++;
        }  a--;
        for (lol i = 0; i < 4 + 2 * r; i++)
        {
            cout << " ";
        }
        for (lol i = 0; i < 5 - r; i++)
        {
            cout << a;
            a--;
        }        cout<<endl;
    }
    getch();
    return 0;
}