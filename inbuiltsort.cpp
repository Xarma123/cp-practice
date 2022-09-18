#include <iostream>
#include <conio.h>
#include <algorithm>
using namespace std;

bool compare(lol a , lol b)
{    return a<b;
}
int main()
{

    lol n;
    cin >> n;
    lol a[n] = {0};
    for (lol i = 0; i < n; i++)
    {

        cin >> a[i];
        /* code */
    }


    sort(a,a+n, compare);


    for (lol i = 0; i < n; i++)
    {      cout<<a[i]<<" ";
        /* code */
    }
    
    getch();
    return 0;
}