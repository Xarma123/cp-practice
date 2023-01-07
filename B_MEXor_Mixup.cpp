#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol a, b;
        cin >> a >> b;
        lol x = 0;
        if ((a - 1) % 4 == 0)
            x = a - 1;
        else if ((a - 1) % 4 == 1)
            x = 1;
        else if ((a - 1) % 4 == 2)
            x = a;
        else
            x = 0;

        if (x == b)
            cout << a << endl;
        else
        {
            if ((x ^ b) == a)
                cout << a + 2 << endl;
            else
                cout << a + 1 << endl;
        }
    }

    return 0;
}