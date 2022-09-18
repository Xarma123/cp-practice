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
        if (a > b)
            swap(a, b);
        if (a == b)
            cout << 0 << " " << 0 << endl;
        else if (abs(a - b) == 1)
            cout << 1 << " " << 0 << endl;
        else
        {
            lol r = abs(a - b);
            lol rx = a % r;
            cout << r << " " << min(rx, (r - rx)) << endl;
        }
    }

    return 0;
}