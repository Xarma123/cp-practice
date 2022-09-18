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
        lol d = abs(a - b);
        lol c = ceil((sqrt(1 + 8 * d) - 1) / (long double)2);
        if (d % 2 == (c * (c + 1) / 2) % 2)
        {
            cout << c << endl;
        }
        else
        {
            while (d % 2 != (c * (c + 1) / 2) % 2)
            {
                c++;
            }
            cout << c << endl;
        }
    }

    return 0;
}