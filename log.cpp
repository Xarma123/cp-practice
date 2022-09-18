#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
    float x, a;
    cin >> x;
    a = (x - 1) / x;float c = (x-1)*(x-1)/(2*x*x);
    for (lol i = 0; i < 6; i++)
    { a=a+c;
       c=c*(x-1)/x;
    }
    cout<<a;
   
}