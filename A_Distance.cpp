#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol x, y;
        cin >> x >> y;
        if ((x + y) % 2 == 0)
        {
            if (x == 0 && y == 0)
                cout << 0 << " " << 0 << endl;
            else if ((x + y) % 2 == 0)
            {
                if (x == 0)
                    cout << 0 << " " << (x + y) / 2 << endl;
                else if (y == 0)
                    cout << (x + y) / 2 << " " << 0 << endl;
                else if (y >= x)
                    cout << 1 << " " << ((x + y) / 2) - 1 << endl;
                else
                    cout << ((x + y) / 2) - 1 << " " << 1 << endl;
            }
            else if ((x - y) >= 0 && (x - y) % 2 == 0)
            {
                cout << (x - y) / 2 << " " << y << endl;
            }
            else if ((y - x) >= 0 && (y - x) % 2 == 0)
            {
                cout << x << " " << (y - x) / 2 << endl;
            }
            else
            {
                cout << -1 << " " << -1 << endl;
            }
        }
        else
            cout << -1 << " " << -1 << endl;
    }

    return 0;
}