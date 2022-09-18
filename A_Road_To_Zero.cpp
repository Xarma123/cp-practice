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
        if (x > y)
            swap(x, y);
        lol a, b;
        cin >> a >> b;
        if (b >= 2 * a || x == 0 || y == 0 || ((x < 0) && (y > 0)))
        {
            cout << a * 1ll * (abs(x) + abs(y)) << endl;
        }
        else
        {
            cout << b * 1ll * (abs(x)) + a * 1ll * (abs(y) - abs(x)) << endl;
        }
    }

    return 0;
}