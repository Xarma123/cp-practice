#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    lol n, zero = 0, f = 0;
    cin >> n;

    for (lol i = 0; i < n; i++)
    {
        lol t;
        cin >> t;

        if (t == 0)
            zero++;
        else if(t==5)
        {
            f++;
        }
    }
    if (zero == 0)
        cout << -1;
    else if (f < 9)
        cout << 0;
    else
    {
        f -= f% 9;
        for (lol i = 0; i < f; i++)
        {
            cout << 5;
        }
        for (lol i = 0; i < zero; i++)
        {
            cout << 0;
        }
    }
}