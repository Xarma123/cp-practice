#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main()
{
    lol t;
    cin >> t;
    while (t--)
    {
        lol x1, y1, z1;
        cin >> x1 >> y1 >> z1;
        lol x2, y2, z2;
        cin >> x2 >> y2 >> z2;
        lol ans = 0;
        // x = 0,y=1,z=2
        if (z1 > 0)
        {
            if (y2 >= z1)
            {
                ans += 2 * z1;
                y2 -= z1;
                z1 = 0;
            }
            else
            {
                ans += 2 * y2;
                z1 -= y2;
                y2 = 0;
            }
        }
        if (z1 > 0)
        {
            if (z2 >= z1)
            {

                z2 -= z1;
                z1 = 0;
            }
            else
            {

                z1 -= z2;
                z2 = 0;
            }
        }
        if (z1 > 0)
        {
            if (x2 >= z1)
            {

                x2 -= z1;
                z1 = 0;
            }
            else
            {

                z1 -= x2;
                x2 = 0;
            }
        }
        if (y1 > 0)
        {
            if (y2 >= y1)
            {
                y2 -= y1;
                y1 = 0;
            }
            else
            {
                y1 -= y2;
                y2 = 0;
            }
        }
        if (y1 > 0)
        {
            if (x2 >= y1)
            {
                x2 -= y1;
                y1 = 0;
            }
            else
            {
                y1 -= x2;
                x2 = 0;
            }
        }
        if (y1 > 0)
        {
            if (z2 >= y1)
            {
                ans -= 2 * 1ll * y1;
                z2 -= y1;
                y1 = 0;
            }
            else
            {
                ans -= 2 * 1ll * z2;
                y1 -= z2;
                z2 = 0;
            }
        }
        cout << ans << endl;
    }

    return 0;
}