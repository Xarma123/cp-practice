#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
    lol a;
    cin >> a;
    for (lol i = 1; i <= 10; i++)
    {
        cout<<a<<'*'<<i<<'='<<a*i<<endl;
    }
    getch();
    return 0;
    
}