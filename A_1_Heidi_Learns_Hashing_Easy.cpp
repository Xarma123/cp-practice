#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol r;
    cin >> r;
    lol X = -1;
    lol x = 1;
    lol y;
    while ((r - 1 - x - x * 1ll * x) > 0)
    {
        if ((r - 1 - x - x * 1ll * x) % (2 * 1ll * x) == 0)
        {
            X = x;
            y = (r - 1 - x - x * 1ll * x) / (2 * 1ll * x);
            break;
        }
        x++;
    }
    if (X == -1)
        cout << "NO" << endl;
    else
        cout << X << " " << y << endl;

    return 0;
}