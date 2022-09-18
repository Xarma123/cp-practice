#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol x, n;
        cin >> x >> n;
        if (x % 2 == 0)
        {
            if (n % 4 == 0)
            {
                cout << x << endl;
            }
            else if (n % 4 == 1)
            {
                cout << -n + x << endl;
            }
            else if (n % 4 == 2)
            {
                cout << 1 + x << endl;
            }
            else
                cout << x + n + 1 << endl;
        }
        else
        {
            if (n % 4 == 0)
            {
                cout << x  << endl;
            }
            else if (n % 4 == 1)
            {
                cout << n + x  << endl;
            }
            else if (n % 4 == 2)
            {
                cout << x-1 << endl;
            }
            else
                cout << x - n-1 << endl;
        }
    }

    return 0;
}