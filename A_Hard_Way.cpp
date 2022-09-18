#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        if (y1 == y2)
        {
            if (y1 > y3)
            {
                cout << abs(x1 - x2) << endl;
            }
            else
                cout << 0 << endl;
        }
        else if (y2 == y3)
        {
            if (y2 > y1)
            {
                cout << abs(x2 - x3) << endl;
            }
            else
                cout << 0 << endl;
        }
        else if (y1 == y3)
        {
            if (y1 > y2)
            {
                cout << abs(x1 - x3) << endl;
            }
            else
                cout << 0 << endl;
        }
        else
            cout << 0 << endl;
    }

    return 0;
}