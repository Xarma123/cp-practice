#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{

    lol n;
    cin >> n;
    if (n == 1)
    {
        cout << 1 << endl;
    }
    else if (n == 2)
    {
        cout << 1 << " " << 2 << endl;
    }
    else if (n == 3)
    {
        cout << 1 << " " << 1 << " " << 3 << endl;
    }
    else if (n == 4)
    {
        cout << "1 1 2 4" << endl;
    }
    else if (n == 5)
    {
        cout << "1 1 1 2 4" << endl;
    }
    else
    {
        lol c = 1;
        while (n > 3)
        {
            for (lol i = 0; i < n - (n / 2); i++)
            {
                cout << c << " ";
            }
            n /= 2;
            c *= 2;
        }
        if (n == 3)
            cout << c << " " << c << " " << 3 * c << endl;
        else if (n == 2)
            cout << c << " " << 2 * 1ll * c << endl;
        else
            cout << c << endl;
    }

    return 0;
}