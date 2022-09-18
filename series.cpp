#include <iostream>
#include <conio.h>
#include <cmath>
using namespace std;
int main()

{
    lol n;
    cin >> n;
    lol d, s = 0;
    for (lol i = 1; i <= n; i++)
    {
        lol a = i;
        for (lol j = i - 1; j >= 1; j--)
        {
            a *= j;
        }  d = i/a;

        s+=d;
    }    cout<<s;
    getch();
    return 0;
}